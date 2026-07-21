//1260. Shift 2D Grid
class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        int total_elem = rows * cols;
        
        k = k % total_elem;
        if (k == 0) return grid;
        
        // Create an answer grid of the exact same dimensions
        vector<vector<int>> result(rows, vector<int>(cols));
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // Calculate the new flat index
                int new_flat_idx = (i * cols + j + k) % total_elem;
                
                // Map it directly to the new 2D position
                result[new_flat_idx / cols][new_flat_idx % cols] = grid[i][j];
            }
        }
        
        return result;
    }
};
