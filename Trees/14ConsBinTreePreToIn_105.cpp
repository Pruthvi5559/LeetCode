//105. Construct Binary Tree from Preorder and Inorder Traversal
/*
Given two integer arrays preorder and inorder where preorder is 
the preorder traversal of a binary tree and inorder is the 
inorder traversal of the same tree, construct and return the binary tree.
*/

class Solution {
private:
    TreeNode* build(const vector<int>& preorder, int pre_start, int pre_end,
                    const vector<int>& inorder, int in_start, int in_end,
                    const unordered_map<int, int>& in_map) {
        if (pre_start > pre_end || in_start > in_end)
            return nullptr;

        int root_val = preorder[pre_start];
        TreeNode* root = new TreeNode(root_val);

        // Find root position in inorder array and calculate left subtree size
        int in_index = in_map.at(root_val);
        int left_size = in_index - in_start;

        root->left = build(preorder, pre_start + 1, pre_start + left_size,
                           inorder, in_start, in_index - 1, in_map);
        root->right = build(preorder, pre_start + left_size + 1, pre_end,
                            inorder, in_index + 1, in_end, in_map);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> in_map;
        for (int i = 0; i < inorder.size(); ++i) {
            in_map[inorder[i]] = i;
        }

        return build(preorder, 0, preorder.size() - 1, inorder, 0,
                     inorder.size() - 1, in_map);
    }
};