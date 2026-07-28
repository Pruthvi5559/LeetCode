//1248. Count Number of Nice Subarrays
class Solution {
private:
    // Returns the number of subarrays containing at most 'k' odd numbers
    int atMost(vector<int>& nums, int k) {

        // If k is negative, no valid subarray can exist
        if (k < 0) return 0;

        int n = nums.size();

        // Sliding window pointers
        int l = 0, r = 0;

        // 'sum' stores the count of odd numbers in the current window
        // 'cnt' stores the total number of valid subarrays
        int cnt = 0, sum = 0;

        while (r < n) {

            // Include the current element in the window
            // nums[r] % 2 is 1 if odd, 0 if even
            sum += nums[r] % 2;

            // Shrink the window until it contains at most k odd numbers
            while (sum > k) {
                sum -= nums[l] % 2;
                l++;
            }

            // All subarrays ending at 'r' and starting from
            // any index between 'l' and 'r' are valid
            cnt += (r - l + 1);

            // Expand the window
            r++;
        }

        return cnt;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        // Number of subarrays with exactly k odd numbers
        // = (Subarrays with at most k odd numbers)
        // - (Subarrays with at most (k - 1) odd numbers)
        return atMost(nums, k) - atMost(nums, k - 1);
    }
};