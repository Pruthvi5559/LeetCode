//42. Trapping Rain Water
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        // Maximum height seen from left and right
        int lmax = 0, rmax = 0;

        int total = 0;
        int l = 0, r = n - 1;

        while (l < r) {

            // Process the side with the smaller height
            if (height[l] <= height[r]) {

                // Water trapped at current left index
                if (lmax > height[l]) {
                    total += (lmax - height[l]);
                } else {
                    lmax = height[l];
                }

                l++;
            } else {

                // Water trapped at current right index
                if (rmax > height[r]) {
                    total += (rmax - height[r]);
                } else {
                    rmax = height[r];
                }

                r--;
            }
        }

        return total;
    }
};