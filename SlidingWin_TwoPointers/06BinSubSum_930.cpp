//930. Binary Subarrays With Sum
class Solution {
private:
    // Returns the number of subarrays whose sum is at most 'goal'
    int atMost(vector<int>& nums, int goal) {

        // No subarray can have a negative sum in a binary array
        if (goal < 0) return 0;

        int n = nums.size();

        // Sliding window pointers
        int l = 0, r = 0;

        // Stores the current window sum and answer
        int sum = 0, cnt = 0;

        while (r < n) {

            // Expand the window by including nums[r]
            sum += nums[r];

            // Shrink the window until its sum becomes <= goal
            while (sum > goal) {
                sum -= nums[l];
                l++;
            }

            // All subarrays ending at 'r' and starting from
            // any index between 'l' and 'r' are valid
            cnt += (r - l + 1);

            // Move the right pointer forward
            r++;
        }

        return cnt;
    }

public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        // Subarrays with sum exactly = goal
        // = Subarrays with sum <= goal
        // - Subarrays with sum <= (goal - 1)
        return atMost(nums, goal) - atMost(nums, goal - 1);
    }
};