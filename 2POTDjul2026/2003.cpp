//3620. Network Recovery Pathways
class Solution {
public:
    using ll = long long;
    const ll INF = 4e18;
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online,
                         long long k) {
        int n = online.size();

        vector<vector<pair<int, int>>> g(n);
        vector<int> indeg(n, 0);

        int hi = 0;

        for (auto& e : edges) {
            g[e[0]].push_back({e[1], e[2]});
            indeg[e[1]]++;
            hi = max(hi, e[2]);
        }

        vector<int> topo;
        queue<int> q;

        vector<int> deg = indeg;

        for (int i = 0; i < n; i++) {
            if (deg[i] == 0)
                q.push(i);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            topo.push_back(u);

            for (auto& [v, w] : g[u]) {
                if (--deg[v] == 0)
                    q.push(v);
            }
        }

        auto check = [&](int limit) -> bool {
            vector<ll> dist(n, INF);
            dist[0] = 0;

            for (int u : topo) {

                if (dist[u] == INF)
                    continue;

                if (u != 0 && u != n - 1 && !online[u])
                    continue;

                for (auto& [v, w] : g[u]) {

                    if (w < limit)
                        continue;

                    if (v != n - 1 && !online[v])
                        continue;

                    if (dist[v] > dist[u] + w) {
                        dist[v] = dist[u] + w;
                    }
                }
            }

            return dist[n - 1] <= k;
        };

        int lo = 0;
        int ans = -1;

        while (lo <= hi) {

            int mid = lo + (hi - lo) / 2;

            if (check(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};