// Question Link :- https://leetcode.com/problems/binary-tree-preorder-traversal
// Binary Tree Preorder Morris Traversal

// T.C = O(N)
// S.C = O(1)
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
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
                if (temp->right == NULL) {
                    ans.push_back(curr->val);
                    temp->right = curr;
                    curr = curr->left;
                } else {
                    temp->right = NULL;
                    curr = curr->right;
                }
            }
        }
        return ans;
    }
};
