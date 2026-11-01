//453. Minimum Moves to Equal Array Elements
/*
Given an integer array nums of size n, 
return the minimum number of moves required to make all array elements equal.

In one move, you can increment n - 1 elements of the array by 1.
*/

class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_val = *min_element(nums.begin(), nums.end());
        long long moves = 0;

        for(int num : nums){
            moves += (num - min_val);
        }

        return moves;
    }
};