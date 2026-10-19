//98. Validate Binary Search Tree
/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:
The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.
*/

class Solution {
private:
    bool check(TreeNode* root, long long min_val, long long max_val){
        if(root == NULL) return true;
        if(root->val <= min_val || root->val >= max_val) return false;
        return check(root->left, min_val, root->val) && check(root->right, root->val, max_val);
    }
public:
    bool isValidBST(TreeNode* root) {
        return check(root, LLONG_MIN, LLONG_MAX);
    }
};