// Question Link :- https://leetcode.com/problems/search-in-a-binary-search-tree/description/
// Search in a Binary Search Tree

// T.C = O(logN)
// S.C = O(logN)

// Approach - 1 (Recursive)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == NULL) {
            return NULL;
        }
        if(root->val == val) {
            return root;
        }
        else if(root->val > val) {
            return searchBST(root->left, val);
        }
        else {
            return searchBST(root->right, val);
        }
    }
};




// Approach - 2 (Iterative)
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL) {
            if(root->val == val) {
                return root;
            }
            if(root->val > val) {
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
        return NULL;
    }
};
