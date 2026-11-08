//1882. Process Tasks Using Servers
/*
You are given two 0-indexed integer arrays servers and tasks of lengths n​​​​​​ and m​​​​​​ respectively. 
servers[i] is the weight of the i​​​​​​th​​​​ server, and tasks[j] is the time needed to process the j​​​​​​th​​​​ task in seconds.
Tasks are assigned to the servers using a task queue. Initially, all servers are free, and the queue is empty.

At second j, the jth task is inserted into the queue (starting with the 0th task being inserted at second 0). 
As long as there are free servers and the queue is not empty, the task in the front of the queue will be 
assigned to a free server with the smallest weight, and in case of a tie, it is assigned to a free server with the smallest index.

If there are no free servers and the queue is not empty, we wait until a server becomes free and 
immediately assign the next task. If multiple servers become free at the same time, then multiple tasks 
from the queue will be assigned in order of insertion following the weight and index priorities above.

A server that is assigned task j at second t will be free again at second t + tasks[j].
Build an array ans​​​​ of length m, where ans[j] is the index of the server the j​​​​​​th task will 
be assigned to.
Return the array ans​​​​.
*/

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int m = servers.size(), n = tasks.size();

        // idle: {weight, index}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> idle;
        // busy: {free_time, index}
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;

        for (int i = 0; i < m; ++i) {
            idle.push({servers[i], i});
        }

        vector<int> ans;
        long long cur_time = 0;

        for (int i = 0; i < n; ++i) {
            cur_time = max(cur_time, (long long)i);

            // Free servers that finished by cur_time
            while (!busy.empty() && busy.top().first <= cur_time) {
                int idx = busy.top().second;
                busy.pop();
                idle.push({servers[idx], idx});
            }

            // Fast-forward time if no idle servers
            if (idle.empty()) {
                cur_time = busy.top().first;
                while (!busy.empty() && busy.top().first <= cur_time) {
                    int idx = busy.top().second;
                    busy.pop();
                    idle.push({servers[idx], idx});
                }
            }

            // Assign server
            auto [weight, idx] = idle.top();
            idle.pop();

            ans.push_back(idx);
            busy.push({cur_time + tasks[i], idx});
        }

        return ans;
    }
};