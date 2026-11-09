//1606. Find Servers That Handled Most Number of Requests
/*
You have k servers numbered from 0 to k-1 that are being used 
to handle multiple requests simultaneously. Each server has 
infinite computational capacity but cannot handle more 
than one request at a time. The requests are assigned to 
servers according to a specific algorithm:

The ith (0-indexed) request arrives.
If all servers are busy, the request is dropped (not handled at all).
If the (i % k)th server is available, assign the request to that server.
Otherwise, assign the request to the next available server (wrapping around 
the list of servers and starting from 0 if necessary). For example, 
if the ith server is busy, try to assign the request to the (i+1)th server, then the (i+2)th server, and so on.
You are given a strictly increasing array arrival of positive integers, 
where arrival[i] represents the arrival time of the ith request, and another array load, 
where load[i] represents the load of the ith request (the time it takes to complete). 
Your goal is to find the busiest server(s). A server is considered busiest if it handled the most number of requests successfully among all the servers.

Return a list containing the IDs (0-indexed) of the busiest server(s). You may return the IDs in any order.
*/

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // Stores {free_time, server_id}
        set<int> available; // Stores IDs of currently available servers
        
        for (int i = 0; i < k; ++i) {
            available.insert(i);
        }
        
        vector<int> count(k, 0);
        
        for (int i = 0; i < arrival.size(); ++i) {
            int start = arrival[i];
            int duration = load[i];
            
            // Free up servers whose tasks have finished by the current arrival time
            while (!pq.empty() && pq.top().first <= start) {
                available.insert(pq.top().second);
                pq.pop();
            }
            
            // If no servers are available, drop the request
            if (available.empty()) {
                continue;
            }
            
            // Find the first available server starting from index (i % k)
            auto it = available.lower_bound(i % k);
            if (it == available.end()) {
                it = available.begin();
            }
            
            int server_id = *it;
            available.erase(it);
            
            // Assign task to the chosen server
            pq.push({start + duration, server_id});
            count[server_id]++;
        }
        
        // Find the maximum number of requests handled by any server
        int max_requests = 0;
        for (int c : count) {
            max_requests = max(max_requests, c);
        }
        
        // Collect all servers that handled the maximum number of requests
        vector<int> busiest;
        for (int i = 0; i < k; ++i) {
            if (count[i] == max_requests) {
                busiest.push_back(i);
            }
        }
        
        return busiest;
    }
};