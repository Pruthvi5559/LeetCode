//1658. Minimum Operations to Reduce X to Zero
/*
You are given an integer array nums and an integer x. In one operation, you can either 
remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies 
the array for future operations.

Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.
*/

class Solution {
private:
    int calTotalSum(vector<int>& nums){
        int sum = 0;
        for(int x : nums) sum+=x;
        return sum;
    }

public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int totalSum = calTotalSum(nums);
        int target = totalSum - x;

        //edge case
        if(target < 0) return -1;
        if(target == 0) return n;

        int left = 0;
        int curr = 0;
        int maxi = -1;

        for(int right = 0; right < n; right++){
            // Expand window by adding current element
            curr += nums[right];

            // Shrink window from the left if running sum exceeds target
            while(curr > target && left <= right){
                curr -= nums[left];
                left++;
            }

            // Check if current window matches the target sum
            if(curr == target){
                maxi = max(maxi, right-left+1);
            }
        
        }
        return maxi == -1 ? -1 : n-maxi;
    }
};