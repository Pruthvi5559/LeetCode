//3875. Construct Uniform Parity Array I
/*
You are given an array nums1 of n distinct integers.

You want to construct another array nums2 of length n such that the elements in nums2 are either all odd or all even.

For each index i, you must choose exactly one of the following (in any order):

nums2[i] = nums1[i]
nums2[i] = nums1[i] - nums1[j], for an index j != i
Return true if it is possible to construct such an array, otherwise, return false.
*/

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // If all numbers already have the same parity, keep them as they are.
        // Otherwise, check whether every element can be made to have the same parity
        // by subtracting another element.
        
        // We can make all elements even if there is at least one even number.
        // We can make all elements odd if there is at least one odd number
        // and at least one even number.
        
        return true;
    }
};