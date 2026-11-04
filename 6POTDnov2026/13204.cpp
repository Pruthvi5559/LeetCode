//3505. Minimum Operations to Make Elements Within K Subarrays Equal
/*
You are given an integer array nums and two integers, x and k. You can perform 
the following operation any number of times (including zero):

Increase or decrease any element of nums by 1.
Return the minimum number of operations needed to have at least k 
non-overlapping subarrays of size exactly x in nums, where all elements 
within each subarray are equal
*/

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        
        // cost[i] will store the min operations to make the window starting at index i equal
        vector<long long> cost(n - x + 1, 0);
        multiset<long long> left_half, right_half; // Two multisets to maintain the sliding window median
        long long sum_left = 0, sum_right = 0;

        // Keeps both halves balanced so left_half.rbegin() always gives the exact median
        auto balance = [&]() {
            while (left_half.size() > right_half.size() + 1) {
                long long val = *left_half.rbegin();
                left_half.erase(left_half.find(val));
                sum_left -= val;
                right_half.insert(val);
                sum_right += val;
            }
            while (right_half.size() > left_half.size()) {
                long long val = *right_half.begin();
                right_half.erase(right_half.find(val));
                sum_right -= val;
                left_half.insert(val);
                sum_left += val;
            }
        };

        // Insert new element into the correct multiset based on current median
        auto add = [&](long long val) {
            if (left_half.empty() || val <= *left_half.rbegin()) {
                left_half.insert(val);
                sum_left += val;
            } else {
                right_half.insert(val);
                sum_right += val;
            }
            balance();
        };

        // Remove old element leaving the sliding window
        auto remove = [&](long long val) {
            auto it = left_half.find(val);
            if (it != left_half.end()) {
                left_half.erase(it);
                sum_left -= val;
            } else {
                it = right_half.find(val);
                if (it != right_half.end()) {
                    right_half.erase(it);
                    sum_right -= val;
                }
            }
            balance();
        };

        // Initialize the first window of size x
        for (int i = 0; i < x; ++i) {
            add(nums[i]);
        }

        // Calculate cost to make current window elements equal to their median
        auto get_cost = [&]() {
            long long median = *left_half.rbegin();
            return (sum_right - (long long)right_half.size() * median) + 
                   ((long long)left_half.size() * median - sum_left);
        };

        cost[0] = get_cost();

        // Slide the window across the array: remove outgoing element, add incoming element
        for (int i = x; i < n; ++i) {
            remove(nums[i - x]);
            add(nums[i]);
            cost[i - x + 1] = get_cost();
        }

        // DP table: dp[j][i] = min cost using j non-overlapping windows up to index i
        int m = cost.size();
        vector<vector<long long>> dp(k + 1, vector<long long>(m + 1, 1e18));

        // Base case: 0 windows cost 0 operations
        for (int i = 0; i <= m; ++i) {
            dp[0][i] = 0;
        }

        // Transition: pick k non-overlapping windows spaced at least x apart
        for (int j = 1; j <= k; ++j) {
            long long min_prev = 1e18;
            for (int i = 1; i <= m; ++i) {
                // Ensure non-overlapping condition (distance >= x between windows)
                min_prev = min(min_prev, dp[j - 1][max(0, i - x)]);
                // Choose whether to include the current window option or skip it
                dp[j][i] = min(dp[j][i - 1], min_prev + cost[i - 1]);
            }
        }

        return dp[k][m];
    }
};