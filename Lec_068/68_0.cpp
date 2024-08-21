// Question Link :- https://leetcode.com/problems/binary-tree-inorder-traversal
// Binary Tree Inorder Morris Traversal

// T.C = O(N)
// S.C = O(1)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode* curr = root;
        while (curr != NULL) {
            if (curr->left == NULL) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode* temp = curr->left;
                while (temp->right != NULL && temp->right != curr) {
                    temp = temp->right;
                }
                if (temp->right == NULL) {   // Make a temporary link to the current node 
                    temp->right = curr;
                    curr = curr->left;
                } else {   // Remove the temporary link
                    temp->right = NULL;
                    ans.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
