//144. Binary Tree Preorder Traversal
/**
 *Given the root of a binary tree, return the preorder traversal of its nodes' values.
 */

class Solution {
public:
    void traverse(TreeNode* root, vector<int>& res) {
        if (root == NULL) return; // Base case

        res.push_back(root->val);   // Visit Root
        traverse(root->left, res);  // Visit Left
        traverse(root->right, res); // Visit Right
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;     // Output array
        traverse(root, res); // Populate array
        return res;          // Return result
    }
};