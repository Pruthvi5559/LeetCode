//2265. Count Nodes Equal to Average of Subtree
/*
Given the root of a binary tree, return the number 
of nodes where the value of the node is equal to the average 
of the values in its subtree.

Note:
The average of n elements is the sum of the n elements divided 
by n and rounded down to the nearest integer.
A subtree of root is a tree consisting of root and all of its descendants.
*/

class Solution {
public:
    int result = 0; // Tracks nodes matching subtree average

    pair<int, int> solve(TreeNode* root) {
        if (!root) return {0, 0}; // Base case

        // Post-order traversal: collect data from children first
        auto l = solve(root->left);
        auto r = solve(root->right);

        // Sum and count for current subtree
        int totalSum = l.first + r.first + root->val;
        int totalCnt = l.second + r.second + 1;

        int avg = totalSum / totalCnt;
        if (avg == root->val) {
            result++;
        }

        return {totalSum, totalCnt};
    }

    int averageOfSubtree(TreeNode* root) {
        result = 0; // Reset counter for clean runs
        solve(root);
        return result;
    }
};