//106. Construct Binary Tree from Inorder and Postorder Traversal
/*
Given two integer arrays inorder and postorder where inorder is 
the inorder traversal of a binary tree and postorder is the 
postorder traversal of the same tree, construct and return the binary tree.
*/

class Solution {
private:
    TreeNode* build(const vector<int>& postorder, int post_start, int post_end,
                    const vector<int>& inorder, int in_start, int in_end,
                    const unordered_map<int, int>& in_map) {
        if (post_start < post_end || in_start > in_end)
            return nullptr;

        int root_val = postorder[post_start];
        TreeNode* root = new TreeNode(root_val);

        // Find root position in inorder array and calculate subtree sizes
        int in_index = in_map.at(root_val);
        int left_size = in_index - in_start;
        int right_size = in_end - in_index;

        // Right subtree root is right before the current root (post_start - 1)
        // Its lower bound in postorder is post_start - right_size
        root->right = build(postorder, post_start - 1, post_start - right_size,
                    inorder, in_index + 1, in_end, in_map);
        
        // Left subtree root comes before the right subtree
        // Its lower bound in postorder is post_end
        root->left = build(postorder, post_start - right_size - 1, post_end,
                           inorder, in_start, in_index - 1, in_map);

        return root;
    }    

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> in_map;
        for (int i = 0; i < inorder.size(); ++i) {
            in_map[inorder[i]] = i;
        }

        return build(postorder, postorder.size()-1, 0, inorder, 0,
                     inorder.size() - 1, in_map);
    }
};
