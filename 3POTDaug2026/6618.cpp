// 3471. Find the Largest Almost Missing Integer

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // Count how many size-k subarrays contain each value
        vector<int> count(51, 0);

        for (int i = 0; i <= n - k; i++) {

            // Avoid counting the same value twice in one window
            vector<bool> seen(51, false);

            for (int j = i; j < i + k; j++) {
                seen[nums[j]] = true;
            }

            // Count this window for each value present
            for (int x = 0; x <= 50; x++) {
                if (seen[x]) {
                    count[x]++;
                }
            }
        }

        // Find the largest almost-missing integer
        for (int x = 50; x >= 0; x--) {
            if (count[x] == 1) {
                return x;
            }
        }

        return -1;
    }
};