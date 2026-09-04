//3876. Construct Uniform Parity Array II
/*
You are given an array nums1 of n distinct integers.

You want to construct another array nums2 of length n such that the elements in nums2 are either all odd or all even.

For each index i, you must choose exactly one of the following (in any order):

nums2[i] = nums1[i]​​​​​​​
nums2[i] = nums1[i] - nums1[j], for an index j != i, such that nums1[i] - nums1[j] >= 1
Return true if it is possible to construct such an array, otherwise return false.

*/

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        int cntEven = 0, cntOdd = 0;
        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == 1) {
                cntOdd++;
            } else {
                cntEven++;
            }
        }
        if (cntOdd == 0)
            return true;
        if (cntEven == 0)
            return true;
        return nums1[0] % 2 == 1;
    }
};