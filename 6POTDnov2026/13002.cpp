//462. Minimum Moves to Equal Array Elements II
/*
Given an integer array nums of size n, return the minimum 
number of moves required to make all array elements equal.

In one move, you can increment or decrement an element of the array by 1.
Test cases are designed so that the answer will fit in a 32-bit integer.
*/

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        // Sort to find median
        sort(nums.begin(), nums.end());
        
        int median = nums[nums.size() / 2];
        int moves = 0;
        
        // Cal abs diff from the median for each element
        for (int num : nums) {
            moves += abs(num - median);
        }
        
        return moves;
    }
};