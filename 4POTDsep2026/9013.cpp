//835. Image Overlap
/*
You are given two images, img1 and img2, represented as binary, 
square matrices of size n x n. A binary matrix has only 0s and 1s as values.

We translate one image however we choose by sliding all the 1 bits 
left, right, up, and/or down any number of units. We then place it on top of the other image.
We can then calculate the overlap by counting the number of positions that have a 1 in both images.

Note also that a translation does not include any kind of rotation. Any 1 bits that are translated 
outside of the matrix borders are erased.

Return the largest possible overlap.
*/

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1, ones2;

        // Collect coordinates of all 1s
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) ones1.push_back({r, c});
                if (img2[r][c] == 1) ones2.push_back({r, c});
            }
        }

        unordered_map<int, int> count;
        int maxOverlap = 0;

        // Compute offset vectors for every pair of 1s
        for (auto& [r1, c1] : ones1) {
            for (auto& [r2, c2] : ones2) {
                int dr = r2 - r1;
                int dc = c2 - c1;
                // Encode (dr, dc) into a unique integer key since N <= 30
                int key = dr * 100 + dc;
                count[key]++;
                maxOverlap = max(maxOverlap, count[key]);
            }
        }

        return maxOverlap;
    }
};