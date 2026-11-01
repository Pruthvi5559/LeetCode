//3619. Count Islands With Total Value Divisible by K
/*
You are given an m x n matrix grid and a positive integer k.\
An island is a group of positive integers (representing land) 
that are 4-directionally connected (horizontally or vertically).

The total value of an island is the sum of the values of all cells in the island.
Return the number of islands with a total value divisible by k.
*/

class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    // BFS to find the total value of the island
                    long long islandSum = 0;
                    queue<pair<int, int>> q;
                    
                    q.push({i, j});
                    visited[i][j] = true;
                    
                    while (!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();
                        
                        islandSum += grid[r][c];
                        
                        for (int d = 0; d < 4; ++d) {
                            int nr = r + dr[d];
                            int nc = c + dc[d];
                            
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && 
                                grid[nr][nc] > 0 && !visited[nr][nc]) {
                                visited[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }
                    
                    if (islandSum % k == 0) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};