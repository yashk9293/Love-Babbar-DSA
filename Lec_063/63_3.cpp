// Question Link :- https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1
// Determine if Two Trees are Identical

// T.C = O(n+m)
// S.C = O(height)
class Solution {
    public:
    bool isIdentical(Node *r1, Node *r2) {
        if(r1 == NULL && r2 == NULL) {
            return true;
        }
        if(r1 != NULL && r2 == NULL) {
            return false;
        }
        if(r1 == NULL && r2 != NULL) {
            return false;
        }
        
        bool left = isIdentical(r1->left, r2->left);
        bool right = isIdentical(r1->right, r2->right);
        bool value = r1->data == r2-> data;
        
        if(left && right && value) {
            return true;
        }
        else {
            return false;
        }
    }
};









// Question Link :- https://leetcode.com/problems/same-tree/
// Same Tree

// T.C = O(n+m)
// S.C = O(height)
class Solution {
public:
    bool check(TreeNode* node1, TreeNode* node2) {
        if(node1 == NULL && node2 == NULL) {
            return true;
        }
        // If only one of the nodes is NULL, they are not identical
        if(node1 == NULL || node2 == NULL) {
            return false;
        }
        return ((node1->val == node2->val) && check(node1->left, node2->left) && check(node1->right, node2->right));
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return check(p, q);
    }
};
