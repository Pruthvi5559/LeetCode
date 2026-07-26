//239. Sliding Window Maximum
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ans;

        // Monotonic decreasing deque (stores indices)
        deque<int> dq;

        for (int i = 0; i < n; i++) {

            // Remove indices that are outside the current window
            if (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // Remove smaller elements as they can never be the maximum
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // Add current index
            dq.push_back(i);

            // First window is formed when i >= k-1
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};