//3904. Smallest Stable Index II
/*
You are given an integer array nums of length n and an integer k.
For each index i, define its instability score as max(nums[0..i]) - min(nums[i..n - 1]).

In other words:
max(nums[0..i]) is the largest value among the elements from index 0 to index i.
min(nums[i..n - 1]) is the smallest value among the elements from index i to index n - 1.
An index i is called stable if its instability score is less than or equal to k.

Return the smallest stable index. If no such index exists, return -1.
*/

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefMax(n);
        vector<int> suffMin(n);

        // Store the maximum value from index 0 to i.
        prefMax[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefMax[i] = max(prefMax[i - 1], nums[i]);
        }

        // Store the minimum value from index i to n - 1.
        suffMin[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            suffMin[i] = min(suffMin[i + 1], nums[i]);
        }

        // Find the smallest stable index.
        for (int i = 0; i < n; i++) {
            int instabilityScore = prefMax[i] - suffMin[i];

            if (instabilityScore <= k) {
                return i;
            }
        }

        // No stable index exists.
        return -1;
    }
};

