//124. Binary Tree Maximum Path Sum
/*
A path in a binary tree is a sequence of nodes where each pair 
of adjacent nodes in the sequence has an edge connecting them. 
A node can only appear in the sequence at most once. 
Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.
Given the root of a binary tree, return the maximum path sum of any non-empty path.
*/

class Solution {
private:
    int dfs(TreeNode* root, int& sum){
        if(root == NULL) return 0;

        int ls = max(0, dfs(root->left, sum));
        int rs = max(0, dfs(root->right, sum));
        sum = max(sum, ls+rs+root->val);

        return root->val + max(ls, rs);
    }

public:
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        dfs(root, sum);
        return sum;
    }
};