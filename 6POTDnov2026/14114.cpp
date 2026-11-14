//3364. Minimum Positive Sum Subarray 
/*
You are given an integer array nums and two integers l and r. 
Your task is to find the minimum sum of a subarray whose size is 
between l and r (inclusive) and whose sum is greater than 0.

Return the minimum sum of such a subarray. 
If no such subarray exists, return -1.

A subarray is a contiguous non-empty sequence of elements within an array.
*/

class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int res = INT_MAX;

        for (int i = l; i < r + 1; i++) {
            int sum = 0;
            for (int right = 0; right < nums.size(); right++) {
                int left = right - i + 1;
                sum += nums[right];
                if (left >= 0) {
                    if (sum > 0) {
                        res = min(res, sum); 
                    }
                    sum -= nums[left];       
                }
            }
        }
        
        if (res == INT_MAX) {
            return -1;
        }
        return res;
    }
};