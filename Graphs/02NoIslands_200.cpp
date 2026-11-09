//200. Number of Islands
/*
Given an m x n 2D binary grid grid which represents a map of 
'1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting 
adjacent lands horizontally or vertically. You may assume all 
four edges of the grid are all surrounded by water.
*/

class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c, int m, int n){
        if(r<0 || r>=m || c<0 || c>=n || grid[r][c]=='0'){
            return;
        }

        grid[r][c] = '0';

        //recursively visit all 4 connected neighbors
        dfs(grid, r-1, c, m, n); //Up
        dfs(grid, r+1, c, m, n); //Down
        dfs(grid, r, c-1, m, n); //Left
        dfs(grid, r, c+1, m, n); //Right
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty() || grid[0].empty()) return 0;

        int m = grid.size();
        int n = grid[0].size();
        int islands = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    islands++;
                    dfs(grid, i, j, m, n);
                }
            }
        }

        return islands;
    }
};