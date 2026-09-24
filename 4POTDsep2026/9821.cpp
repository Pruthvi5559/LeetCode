//3524. Find X Value of Array I
/*
You are given an array of positive integers nums, and a positive integer k.
You are allowed to perform an operation once on nums, where in each operation you 
can remove any non-overlapping prefix and suffix from nums such that nums remains non-empty.
You need to find the x-value of nums, which is the number of ways to perform this 
operation so that the product of the remaining elements leaves a remainder of x when divided by k.

Return an array result of size k where result[x] is the x-value of nums for 0 <= x <= k - 1.
A prefix of an array is a subarray that starts from the beginning of the array and extends to any point within it.
A suffix of an array is a subarray that starts at any point within the array and extends to the end of the array.

Note that the prefix and suffix to be chosen for the operation can be empty.
*/

class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> current(k, 0);

            int remainder = num % k;

            // Start a new subarray with the current element.
            current[remainder]++;

            // Extend all subarrays ending at the previous index.
            for (int r = 0; r < k; r++) {
                if (dp[r] == 0)
                    continue;

                int newRemainder = (r * remainder) % k;

                current[newRemainder] += dp[r];
            }

            // Count subarrays ending at the current index.
            for (int r = 0; r < k; r++) {
                result[r] += current[r];
            }

            dp = current;
        }

        return result;
    }
};