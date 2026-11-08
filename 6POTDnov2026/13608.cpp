//1267. Count Servers that Communicate
/*
You are given a map of a server center, represented as a m * n 
integer matrix grid, where 1 means that on that cell there is a 
server and 0 means that it is no server. Two servers are said to 
communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.
*/

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<int> rowCount(m, 0);
        vector<int> colCount(n, 0);
        
        // Cnt servers in each row & col
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    rowCount[i]++;
                    colCount[j]++;
                }
            }
        }
        
        //Cnt servers that can communicate
        int count = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    if (rowCount[i] > 1 || colCount[j] > 1) {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};