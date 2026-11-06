//2747. Count Zero Request Servers
/*
You are given an integer n denoting the total number of servers and a 2D 0-indexed integer array logs,
where logs[i] = [server_id, time] denotes that the server with id server_id received a request at time time.
You are also given an integer x and a 0-indexed integer array queries.

Return a 0-indexed integer array arr of length queries.length where arr[i] represents the number 
of servers that did not receive any requests during the time interval [queries[i] - x, queries[i]].

Note that the time intervals are inclusive
*/


class Solution {
public:
    std::vector<int> countServers(int n, std::vector<std::vector<int>>& logs, int x, std::vector<int>& queries) {
        // Sort logs in ascending order of their timestamps
        std::sort(logs.begin(), logs.end(), [](const auto& a, const auto& b) {
            return a[1] < b[1];
        });

        // Store original indices of queries so we can place answers correctly
        std::vector<int> ids(queries.size());
        std::iota(ids.begin(), ids.end(), 0);
        std::sort(ids.begin(), ids.end(), [&](int i, int j) {
            return queries[i] < queries[j];
        });

        std::vector<int> ans(queries.size());
        std::vector<int> cnt(n + 1, 0);
        int left = 0, right = 0, active = 0;

        for (int i : ids) {
            int q = queries[i];
            
            // Expand the window to include all logs with time <= q
            while (right < logs.size() && logs[right][1] <= q) {
                int id = logs[right++][0];
                if (cnt[id]++ == 0) {
                    ++active;
                }
            }
            
            // Shrink the window to exclude logs with time < q - x
            while (left < right && logs[left][1] < q - x) {
                int id = logs[left++][0];
                if (--cnt[id] == 0) {
                    --active;
                }
            }
            
            // The number of servers with zero requests is total servers minus active servers
            ans[i] = n - active;
        }

        return ans;
    }
};