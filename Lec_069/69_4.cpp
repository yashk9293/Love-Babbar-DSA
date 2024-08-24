// Binary Search Tree Inorder Successor and Predecessor
// S.C = O(h)
// T.C = O(1)

class Solution {
public:
    TreeNode * inorderPredecessor(TreeNode * root, TreeNode * p) {
        TreeNode* successor = NULL;
        while(root!=NULL){
            if(p->val >= root->val){
                root = root->right;
            }
            else{
                successor = root;
                root = root->left;
            }
        }
        return successor;
    }
};



class Solution {
public:
    TreeNode * inorderPredecessor(TreeNode * root, TreeNode * p) {
        TreeNode* predecessor = NULL;
        while(root!=NULL){
            if(root->val >= p->val){
                root = root->left;
            }
            else{
                predecessor = root;
                root = root->right;
            }
        }
        return predecessor;
    }
};
