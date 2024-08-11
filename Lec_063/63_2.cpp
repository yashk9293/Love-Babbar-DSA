// Question Link :- https://leetcode.com/problems/balanced-binary-tree
// Balanced Binary Tree (Striver)


// T.C = O(N)
// S.C = O(height)
class Solution {
public:
    int solve(TreeNode* root, bool& result) {
        if(root == NULL) {
            return 0;
        }
        int leftHeight = solve(root->left, result);
        int rightHeight = solve(root->right, result);

        if(abs(leftHeight - rightHeight) > 1) {
            return result = 0;
        }
        return 1 + max(leftHeight, rightHeight); // to calculate the height of left and right subtree...
    }
    bool isBalanced(TreeNode* root) {
        bool result = 1;
        solve(root, result);
        return result;
    }
};
