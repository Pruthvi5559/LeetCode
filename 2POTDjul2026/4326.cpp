//628. Maximum Product of Three Numbers
class Solution {
public:
    int maximumProduct(vector<int>& nums) {

        // Three largest numbers
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

        // Two smallest numbers
        int min1 = INT_MAX, min2 = INT_MAX;

        for (int num : nums) {

            // Update three largest numbers
            if (num >= max1) {
                max3 = max2;
                max2 = max1;
                max1 = num;
            }
            else if (num >= max2) {
                max3 = max2;
                max2 = num;
            }
            else if (num >= max3) {
                max3 = num;
            }

            // Update two smallest numbers
            if (num <= min1) {
                min2 = min1;
                min1 = num;
            }
            else if (num <= min2) {
                min2 = num;
            }
        }

        // Maximum product is either:
        // 1. Product of three largest numbers
        // 2. Product of two smallest (most negative) and the largest number
        return max(max1 * max2 * max3,
                   min1 * min2 * max1);
    }
};