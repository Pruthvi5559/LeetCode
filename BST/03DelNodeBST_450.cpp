//450. Delete Node in a BST
/*
Given a root node reference of a BST and a key, 
delete the node with the given key in the BST. 
Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:
Search for a node to remove.
If the node is found, delete the node.
*/

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        // If the key matches, use your helper function to delete this node
        if(root->val == key) return helper(root);
        
        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } else {
            root->right = deleteNode(root->right, key);
        }
        
        return root;
    }

    TreeNode* helper(TreeNode* root){
        if(root->left == NULL){
            return root->right;
        }
        else if(root->right == NULL){
            return root->left;
        }
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }

    TreeNode* findLastRight(TreeNode* root){
        if(root->right == NULL){
            return root;
        }
        return findLastRight(root->right);
    }
};