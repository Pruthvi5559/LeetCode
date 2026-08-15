// 3702. Longest Subsequence With Non-Zero Bitwise XOR

class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();

        int resXor = 0;
        bool allZero = true;

        // Calculate XOR of all elements
        for (int& x : nums) {
            resXor ^= x;

            // Check whether the array contains any non-zero element
            if (x != 0) {
                allZero = false;
            }
        }

        // If all elements are zero, no non-empty valid subsequence exists
        if (allZero) {
            return 0;
        }

        // If total XOR is zero, remove one non-zero element.
        // Otherwise, the entire array can be used.
        return (resXor == 0) ? n - 1 : n;
    }
};