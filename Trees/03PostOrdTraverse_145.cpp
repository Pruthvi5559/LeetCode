//145. Binary Tree Postorder Traversal
/*Given the root of a binary tree, return the postorder traversal of its nodes' values.*/

class Solution {
public:
    void traverse(TreeNode* root, vector<int>& res){
        if(root == NULL) return ; //base case
 
        traverse(root->left, res); //visit left subtree
        traverse(root->right, res); //visit right subtree
        res.push_back(root->val); // Process current node
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        traverse(root, res);
        return res;
    }
};