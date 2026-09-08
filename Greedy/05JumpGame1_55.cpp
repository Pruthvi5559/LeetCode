//55. Jump Game
/*
You are given an integer array nums. 
You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxIdx = 0; // Tracks furthest reachable index

        for (int i = 0; i < n; i++) {
            if (i > maxIdx) return false;      // Cannot reach current position
            maxIdx = max(maxIdx, i + nums[i]); // Update furthest reach
        }

        return true; // Successfully reached the end
    }
};