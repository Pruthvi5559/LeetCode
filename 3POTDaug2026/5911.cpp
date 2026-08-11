//2996. Smallest Missing Integer Greater Than Sequential Prefix Sum

class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();

        // Find the sum of the longest sequential prefix
        int sum = nums[0];

        for (int i = 1; i < n; i++) {

            // Prefix stops at the first non-consecutive element
            if (nums[i] != nums[i-1]+1)
                break;

            sum += nums[i];
        }

        // Find the smallest missing number >= sum
        int ans = sum;

        while (find(nums.begin(), nums.end(), ans) != nums.end()) {
            ans++;
        }

        return ans;
    }
};