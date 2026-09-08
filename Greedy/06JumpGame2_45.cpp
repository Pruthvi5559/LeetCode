//45. Jump Game II
/*
You are given a 0-indexed array of integers 
nums of length n. You are initially positioned at index 0.

Each element nums[i] represents the maximum length 
of a forward jump from index i. In other words, if you are at index i, 
you can jump to any index (i + j) where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach index n - 1. The test cases 
are generated such that you can reach index n - 1.
 */

 class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int maxIdx = 0; // Farthest index reachable in the next jump
        int jmp = 0; // Total jumps taken
        int currEnd=0; // Farthest index reachable with current number of jumps

        for(int i = 0; i < n-1; i++){
            // Track maximum reach possible
            maxIdx = max(maxIdx, i+nums[i]);

            // When at the end of current jump range, take the next jump
            if(i == currEnd){
                jmp++;
                // Update range boundary for the new jump
                currEnd = maxIdx;
            }
        }
        return jmp;
    }
};