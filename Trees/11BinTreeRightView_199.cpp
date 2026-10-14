//199. Binary Tree Right Side View
/*
Given the root of a binary tree, imagine yourself standing on 
the right side of it, return the values of the nodes you can see ordered from top to bottom.
*/

class Solution {
private:
    void dfs(TreeNode* root, int level, vector<int>& ans){
      if(root == NULL) return;

      if(level == ans.size()){
        ans.push_back(root->val);
      }

      dfs(root->right, level+1, ans);
      dfs(root->left, level+1, ans);
    }

public:
    vector<int> rightSideView(TreeNode* root) {
       vector<int> ans;
       dfs(root, 0, ans);
       return ans;
    }
};