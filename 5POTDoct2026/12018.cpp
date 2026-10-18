//1569. Number of Ways to Reorder Array to Get Same BST
/*
Given an array nums that represents a permutation of integers from 1 to n. 
We are going to construct a binary search tree (BST) by inserting the elements 
of nums in order into an initially empty BST. Find the number of different 
ways to reorder nums so that the constructed BST is identical to that formed from the original array nums.

For example, given nums = [2,1,3], we will have 2 as the root, 1 as a left child, 
and 3 as a right child. The array [2,3,1] also yields the same BST but [3,2,1] 
yields a different BST.
Return the number of ways to reorder nums such that the BST formed is identical 
to the original BST formed from nums.
Since the answer may be very large, return it modulo 109 + 7.
*/

class Solution {
private:
    vector<vector<long long>> comb;
    long long mod = 1e9 + 7;

    long long dfs(const vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        vector<int> left, right;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        long long left_ways = dfs(left);
        long long right_ways = dfs(right);

        int left_len = left.size();
        // Multiply combination ways with subtree results under modulo
        long long ways = (comb[n - 1][left_len] * left_ways) % mod;
        return (ways * right_ways) % mod;
    }

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        
        // Precompute combinations using Pascal's triangle
        comb.assign(n + 1, vector<long long>(n + 1, 0));
        for (int i = 0; i <= n; ++i) {
            comb[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % mod;
            }
        }

        // Subtract 1 to exclude the original array order
        return (dfs(nums) - 1 + mod) % mod;
    }
};