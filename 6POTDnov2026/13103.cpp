//3736. Minimum Moves to Equal Array Elements III
/*You are given an integer array nums.

In one move, you may increase the value of any 
single element nums[i] by 1.
Return the minimum total number of moves required so that all 
elements in nums become equal.
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(nums.begin(), nums.end()); 
        int moves = 0; 
        for(int x : nums) {
            moves += (maxi - x); 
        } 
        return moves;
    }
};
