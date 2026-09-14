//102. Binary Tree Level Order Traversal
/*Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        // Base case: empty tree
        if (root == nullptr) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);

        // Standard BFS level-by-level processing
        while (!q.empty()) {
            int size = q.size(); // Lock size of current tree level
            vector<int> level;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                level.push_back(node->val);

                // FIX: Push the left child if present
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                
                // Push the right child if present
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            
            // Collect node values for the current level
            ans.push_back(level);
        }
        
        return ans;
    }
};