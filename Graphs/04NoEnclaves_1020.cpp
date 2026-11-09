//1020. Number of Enclaves
/*
You are given an m x n binary matrix grid, 
where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent 
(4-directionally) land cell or walking off the boundary of the grid.

Return the number of land cells in grid for which we cannot walk 
off the boundary of the grid in any number of moves.
*/

class Solution {
private:
    void dfs(vector<vector<int>>& grid, int r, int c, int m, int n) {
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == 0) {
            return;
        }
        grid[r][c] = 0; 

        dfs(grid, r + 1, c, m, n);
        dfs(grid, r - 1, c, m, n);
        dfs(grid, r, c + 1, m, n);
        dfs(grid, r, c - 1, m, n);
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            if (grid[i][0] == 1) dfs(grid, i, 0, m, n);
            if (grid[i][n - 1] == 1) dfs(grid, i, n - 1, m, n);
        }
        
        for (int j = 0; j < n; ++j) {
            if (grid[0][j] == 1) dfs(grid, 0, j, m, n);
            if (grid[m - 1][j] == 1) dfs(grid, m - 1, j, m, n);
        }
       
        int enclavesCnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    enclavesCnt++;
                }
            }
        }
        
        return enclavesCnt;
    }
};