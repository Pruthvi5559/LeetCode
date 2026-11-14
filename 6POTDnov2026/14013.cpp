//3420. Count Non-Decreasing Subarrays After K Operations
/*
You are given an array nums of n integers and an integer k.

For each subarray of nums, you can apply up to k operations on it. 
In each operation, you increment any element of the subarray by 1.

Note that each subarray is considered independently, 
meaning changes made to one subarray do not persist to another.

Return the number of subarrays that you can make 
non-decreasing ​​​​​after performing at most k operations.

An array is said to be non-decreasing if each element 
is greater than or equal to its previous element, if it exists.
*/

class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        long long totalSubarrays = 0;
        long long currentCost = 0;
        
        // Monotonic non-decreasing deque storing indices of dominating elements
        // in the current window [l, r] from left to right.
        deque<int> dq;
        int r = n - 1;
        
        // Expand window to the left by moving l from n - 1 down to 0
        for (int l = n - 1; l >= 0; --l) {
            // 1. Add nums[l] to the left of the window:
            // Any element in the deque smaller than nums[l] must be raised to nums[l].
            while (!dq.empty() && nums[dq.front()] < nums[l]) {
                int currIdx = dq.front();
                dq.pop_front();
                
                // Determine the rightmost boundary of the segment controlled by currIdx
                int nextIdx = dq.empty() ? (r + 1) : dq.front();
                
                // Add the cost of raising all elements in [currIdx, nextIdx - 1] to nums[l]
                currentCost += 1LL * (nextIdx - currIdx) * (nums[l] - nums[currIdx]);
            }
            dq.push_front(l);
            
            // 2. Shrink window from the right if operations exceed k
            while (currentCost > k) {
                // The rightmost element r is dominated by dq.back()
                currentCost -= (nums[dq.back()] - nums[r]);
                
                // If r was the exact index of the rightmost dominating element, pop it
                if (dq.back() == r) {
                    dq.pop_back();
                }
                --r;
            }
            
            // 3. All subarrays starting at l and ending at any index in [l, r] are valid
            totalSubarrays += (r - l + 1);
        }
        
        return totalSubarrays;
    }
};