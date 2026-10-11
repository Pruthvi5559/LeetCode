//110. Balanced Binary Tree
/*
Given a binary tree, determine if it is height-balanced.
*/

class Solution {
private:
    int dfs(TreeNode* root){
        if(root == NULL) return 0;

        int lh = dfs(root->left);
        if(lh == -1) return -1;
        int rh = dfs(root->right);
        if(rh == -1) return -1;

        if(abs(lh - rh) > 1) return -1;

        return max(lh, rh) + 1;
    }    
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root) != -1;
    }
};