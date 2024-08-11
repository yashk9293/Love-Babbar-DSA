// Question Link :- https://leetcode.com/problems/diameter-of-binary-tree/
// Diameter of Binary Tree (Aditya Verma)

// T.C = O(n)
// S.C = O(1)
// as no additional space or data structures is created that is proportional to the input size of the tree. O(H) Recursive 
// Stack Auxiliary Space: The recursion stack space is determined by the maximum depth of the recursion, which is the height of 
// the binary tree denoted as H. In the balanced case it is log2N and in the worst case its N.

class Solution {
public:
    int solve(TreeNode* root, int &res) {
        if(root == nullptr) {
            return 0;
        }
        int l = solve(root->left, res);
        int r = solve(root->right, res);

        int temp = 1 + max(l,r);
        int ans = max(temp, 1+l+r);
        res = max(res, ans);

        return temp;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int res = INT_MIN;
        solve(root, res);

        return res-1;      // no. of edges
        
        // Note:- aditya verma had found no.of nodes, but in leetcode we have to find no. of edges 
        // so we have returned (res-1) in the function, for # nodes we would return res.
    }
};
