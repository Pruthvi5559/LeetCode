//1464. Maximum Product of Two Elements in an Array
class Solution {
public:
    int maxProduct(vector<int>& nums) {

        // Stores the largest and second largest elements
        int firstMax = 0;
        int secondMax = 0;

        for (int x : nums) {

            // Found a new largest element
            if (x >= firstMax) {
                secondMax = firstMax;
                firstMax = x;
            }
            // Update second largest only
            else if (x > secondMax) {
                secondMax = x;
            }
        }

        // Return (largest-1)*(secondLargest-1)
        return (firstMax - 1) * (secondMax - 1);
    }
};