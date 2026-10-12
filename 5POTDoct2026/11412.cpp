//2897. Apply Operations on Array to Maximize Sum of Squares
/*
You are given a 0-indexed integer array nums and a positive integer k.
You can do the following operation on the array any number of times:

Choose any two distinct indices i and j and simultaneously update the \
values of nums[i] to (nums[i] AND nums[j]) and nums[j] to (nums[i] OR nums[j]). 
Here, OR denotes the bitwise OR operation, and AND denotes the bitwise AND operation.
You have to choose k elements from the final array and calculate the sum of their squares.

Return the maximum sum of squares you can achieve.
Since the answer can be very large, return it modulo 109 + 7. 
*/

class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bits(30,0);

        for(int n : nums){
            for(int i = 0; i < 30; ++i){
                bits[i] += (n>>i)&1;
            }
        }

        long long res = 0;
        long long mod = 1e9 + 7;

        for(int j = 0; j < k; ++j){
            long long n = 0;
            for(int i = 0; i < 30; ++i){
                if(bits[i] > 0){
                    n |= (1LL << i);
                    bits[i]--;
                }
            }
            res = (res + (n * n)%mod)%mod;

        }

        return res;
    }
};