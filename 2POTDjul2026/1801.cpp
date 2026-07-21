//2812. Find the Safest Path in a Grid
class Solution {
public:
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        // Step 1: Distance to nearest thief
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while (!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            for (auto [dx, dy] : dir) {

                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;

                if (dist[nx][ny] != INT_MAX)
                    continue;

                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }

        // Step 2: Modified Dijkstra
        priority_queue<vector<int>> pq;

        vector<vector<int>> best(n, vector<int>(n, -1));

        pq.push({dist[0][0], 0, 0});
        best[0][0] = dist[0][0];

        while (!pq.empty()) {

            auto curr = pq.top();
            pq.pop();

            int safe = curr[0];
            int x = curr[1];
            int y = curr[2];

            if (x == n - 1 && y == n - 1)
                return safe;

            if (safe < best[x][y])
                continue;

            for (auto [dx, dy] : dir) {

                int nx = x + dx;
                int ny = y + dy;

                if (nx < 0 || ny < 0 || nx >= n || ny >= n)
                    continue;

                int newSafe = min(safe, dist[nx][ny]);

                if (newSafe > best[nx][ny]) {

                    best[nx][ny] = newSafe;

                    pq.push({newSafe, nx, ny});
                }
            }
        }

        return 0;
    }
};