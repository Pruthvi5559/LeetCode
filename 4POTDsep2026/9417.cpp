//1477. Find Two Non-overlapping Sub-arrays Each With Target Sum
/*You are given an array of integers arr and an integer target.

You have to find two non-overlapping sub-arrays of arr each with a 
sum equal target. There can be multiple answers so you have to find an 
answer where the sum of the lengths of the two sub-arrays is minimum.

Return the minimum sum of the lengths of the two required sub-arrays, 
or return -1 if you cannot find such two sub-arrays.
*/

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        vector<int> minLengthUpToIndex(n, INT_MAX);

        int windowStart = 0;
        int windowSum = 0;

        int minSubarrayLength = INT_MAX;
        int minimumTotalLength = INT_MAX;

        for (int windowEnd = 0; windowEnd < n; windowEnd++) {
            windowSum += arr[windowEnd];

            // Shrink the window until its sum is <= target.
            while (windowStart <= windowEnd && windowSum > target) {
                windowSum -= arr[windowStart++];
            }

            if (windowSum == target) {
                int currentLength = windowEnd - windowStart + 1;

                // Combine with the best valid subarray ending before
                // the current subarray starts.
                if (windowStart > 0 &&
                    minLengthUpToIndex[windowStart - 1] != INT_MAX) {
                    minimumTotalLength = min(
                        minimumTotalLength,
                        currentLength + minLengthUpToIndex[windowStart - 1]
                    );
                }

                minSubarrayLength = min(
                    minSubarrayLength,
                    currentLength
                );
            }

            // Best subarray length found up to this index.
            minLengthUpToIndex[windowEnd] = minSubarrayLength;
        }

        return minimumTotalLength == INT_MAX ? -1 : minimumTotalLength;
    }
};