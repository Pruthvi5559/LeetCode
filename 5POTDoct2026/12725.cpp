//1254. Number of Closed Islands
/*
Given a 2D grid consists of 0s (land) 
and 1s (water).  An island is a maximal 
4-directionally connected group of 0s and a 
closed island is an island totally 
(all left, top, right, bottom) surrounded by 1s.

Return the number of closed islands.
*/

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Out of bounds or already water (1)
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 1) {
            return;
        }
        
        // Mark the current cell as visited by turning it into water (1)
        grid[r][c] = 1;
        
        // Traverse in all 4 directions
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // Step 1: Turn all land (0) connected to the boundaries into water (1)
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if ((r == 0 || r == rows - 1 || c == 0 || c == cols - 1) && grid[r][c] == 0) {
                    dfs(grid, r, c);
                }
            }
        }
        
        // Step 2: Count the remaining valid closed islands
        int closedIslandsCount = 0;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0) {
                    closedIslandsCount++;
                    dfs(grid, r, c); // Flood-fill the entire closed island
                }
            }
        }
        
        return closedIslandsCount;
    }
};