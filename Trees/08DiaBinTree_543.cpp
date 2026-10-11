//543. Diameter of Binary Tree
/*
Given the root of a binary tree, return the length of the diameter of the tree.
The diameter of a binary tree is the length of the longest 
path between any two nodes in a tree. This path may or may not pass through the root.
The length of a path between two nodes is represented by the number of edges between them.
*/
class Solution {
private:
    int dfs(TreeNode* root, int& maxi){
        if(root == NULL) return 0;

        int lh = dfs(root->left, maxi);
        int rh = dfs(root->right, maxi);
        maxi = max(maxi, lh+rh);

        return 1 + max(lh, rh);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        dfs(root, dia);
        return dia;
    }
};
