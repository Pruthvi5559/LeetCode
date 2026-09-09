//94. Binary Tree Inorder Traversal
/*Given the root of a binary tree, return the inorder traversal of its nodes' values.*/

class Solution {
public:
    void traverse(TreeNode* root, vector<int>& res){
        if(root == NULL) return ; //base case
        
        traverse(root->left, res); //traverse left
        res.push_back(root->val); //traverse root
        traverse(root->right, res); //traverse right
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res; //output array
        traverse(root, res); //populate array
        return res; //inordered array
    }
};