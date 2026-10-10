//2333. Minimum Sum of Squared Difference
/*
You are given two positive 0-indexed integer arrays nums1 and nums2, both of length n.

The sum of squared difference of arrays nums1 and nums2 is 
defined as the sum of (nums1[i] - nums2[i])2 for each 0 <= i < n.

You are also given two positive integers k1 and k2. You can modify 
any of the elements of nums1 by +1 or -1 at most k1 times. Similarly, 
you can modify any of the elements of nums2 by +1 or -1 at most k2 times.

Return the minimum sum of squared difference after modifying array nums1 
at most k1 times and modifying array nums2 at most k2 times.

Note: You are allowed to modify the array elements to become negative integers.
*/

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long k = (long long)k1 + k2;
        int n = nums1.size();
        
        // absolute differences
        for (int i = 0; i < n; i++) {
            nums1[i] = abs(nums1[i] - nums2[i]);
        }
        
        // If the total operations can reduce all differences to 0
        if (accumulate(nums1.begin(), nums1.end(), 0LL) <= k) {
            return 0;
        }
        
        // Sort in descending order and add a sentinel value
        sort(nums1.begin(), nums1.end(), greater<int>());
        nums1.push_back(0);
        
        // Greedily reduce the largest differences in batches
        for (int i = 1; i <= n; i++) {
            long long cost = (long long)(nums1[i - 1] - nums1[i]) * i;
            if (cost > k) {
                long long q = k / i, r = k % i;
                long long hi = nums1[i - 1] - q;
                
                long long ans = hi * hi * (i - r) + (hi - 1) * (hi - 1) * r;
                for (int j = i; j < n; j++) {
                    ans += (long long)nums1[j] * nums1[j];
                }
                return ans;
            }
            k -= cost;
        }
        
        return 0;
    }
};