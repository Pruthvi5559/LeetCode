//230. Kth Smallest Element in a BST
/*
Given the root of a binary search tree, 
and an integer k, return the kth smallest value (1-indexed) 
of all the values of the nodes in the tree.
*/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        TreeNode* curr = root;

        while(curr != NULL || !st.empty()){
            
            // Reach the leftmost node of the current node
            while(curr != NULL){
                st.push(curr);
                curr = curr->left;
            }

            // Current is null, pop from stack
            curr = st.top();
            st.pop();

            // Decrement k and check if this is our target
            if(--k == 0){
                return curr->val;
            }

            // Move to the right subtree
            curr = curr->right;
        }

        return -1;
    }
};