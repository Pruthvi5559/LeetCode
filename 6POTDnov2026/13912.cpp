//3105. Longest Strictly Increasing or Strictly Decreasing Subarray
/*
You are given an array of integers nums. 
Return the length of the longest subarray of nums 
which is either strictly increasing or strictly decreasing. 
*/

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 1, dec = 1;
        int ans = 1;

        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] > nums[i]) {
                inc++;
                dec = 1;  
            } else if (nums[i + 1] < nums[i]) {
                dec++;
                inc = 1;  
            } else {
                inc = 1;
                dec = 1;
            }

            ans = max(ans, max(inc, dec));
        }
        return ans;
    }
};