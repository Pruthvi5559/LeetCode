//103. Binary Tree Zigzag Level Order Traversal
/*
Given the root of a binary tree, return the zigzag level order 
traversal of its nodes' values. (i.e., from left to right, 
then right to left for the next level and alternate between).
*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;

        while(!q.empty()){
            int size = q.size();
            vector<int> level;

            for(int i=0; i<size; i++){
                TreeNode* node = q.front();
                q.pop();
            
                level.push_back(node->val);
                
                if(node->left != nullptr){
                    q.push(node->left);
                }
                if(node->right != nullptr){
                    q.push(node->right);
                
                }
            }

            if(!leftToRight){
                reverse(level.begin(), level.end());
            }

            ans.push_back(level);
            leftToRight = !leftToRight;
        }
        return ans;
    }
};