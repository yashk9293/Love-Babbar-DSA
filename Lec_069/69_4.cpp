// Question Link :- https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1
// Inorder Successor in BST

// S.C = O(h)
// T.C = O(1)

class Solution {
  public:
    Node * inOrderSuccessor(Node *root, Node *x) {
        Node* suc = NULL;
        while(root != NULL) {
            if(root->data <= x->data) {
                root = root->right;
            } else {
                suc = root;
                root = root->left;
            }
        }
        return suc;
    }
};


// Inorder Predecessor in BST
class Solution {
public:
    TreeNode* inorderPredecessor(TreeNode* root, TreeNode* p) {
        TreeNode* pre = NULL;
        while(root != NULL) {
            if(root->val >= p->val) {
                root = root->left;
            } else {
                pre = root;
                root = root->right;
            }
        }
        return pre;
    }
};
