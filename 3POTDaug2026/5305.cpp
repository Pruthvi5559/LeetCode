//3310. Remove Methods From Project

class Solution {
public:
    void dfs(int u, vector<vector<int>>& adj, vector<int>& vis) {
        vis[u] = 1;

        for (int v : adj[u]) {
            if (!vis[v])
                dfs(v, adj, vis);
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {

        vector<vector<int>> adj(n);

        // Build graph
        for (auto &e : invocations) {
            adj[e[0]].push_back(e[1]);
        }

        // Mark all suspicious methods
        vector<int> vis(n, 0);
        dfs(k, adj, vis);

        // If any non-suspicious method invokes a suspicious one,
        // removal is impossible.
        for (auto &e : invocations) {
            int u = e[0];
            int v = e[1];

            if (!vis[u] && vis[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++)
                    ans.push_back(i);
                return ans;
            }
        }

        // Return remaining methods
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }

        return ans;
    }
};