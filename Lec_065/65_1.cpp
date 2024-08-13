// Question Link :- https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-binary-tree/1
// Lowest Common Ancestor in a Binary Tree

// T.C = O(n)
// S.C = O(height)
class Solution {
public:
    Node *lca(Node *root, int n1, int n2) {
        if (root == NULL) {
            return NULL;
        }
        if (root->data == n1 || root->data == n2) {
            return root;
        }
        Node *leftAns = lca(root->left, n1, n2);
        Node *rightAns = lca(root->right, n1, n2);

        if (rightAns == NULL) {
            return leftAns;
        }
        else if (leftAns == NULL) {
            return rightAns;
        }
        else {  // (leftAns != NULL && rightAns != NULL) -> both are not null, we found our result
            return root;
        }
    }
};
