// Question Link :- https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree
// Lowest Common Ancestor of a Binary Search Tree


// Approach - 1 (Iterative)
// T.C = O(H)
// S.C = O(1)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root != NULL) {
            if (root->val > p->val && root->val > q->val) {  // p, q belong to the left subtree
                root = root->left;
            }
            else if (root->val < p->val && root->val < q->val) {  // p, q belong to the right subtree
                root = root->right;
            }
            else {  // Now, small <= root.val <= large -> This root is the LCA between p and q
                return root;
            }
        }
        return NULL;
    }
};





// Approach - 2 (Recursive)
// T.C = O(H)
// S.C = O(1)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL) {
            return NULL;
        }
        int curr = root->val;
        if(curr < p->val && curr < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        if(curr > p->val && curr > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }
        // if not the above case then we got the lca (either of the p or q is the current node or only one of the node is on left or right side not both of them ) hence the current node will be lca
        return root;
    }
};
