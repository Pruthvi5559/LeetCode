//1004. Max Consecutive Ones III
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int left = 0, right = 0;

        // Maximum valid window length
        int maxlen = 0;

        // Number of zeros in the current window
        int zeroCount = 0;

        while (right < n) {

            // Include current element in the window
            if (nums[right] == 0)
                zeroCount++;

            // Shrink the window until it becomes valid
            while (zeroCount > k) {

                if (nums[left] == 0)
                    zeroCount--;

                left++;
            }

            // Update the maximum window length
            maxlen = max(maxlen, right - left + 1);

            right++;
        }

        return maxlen;
    }
};