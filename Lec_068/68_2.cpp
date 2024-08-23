// Question Link :- https://leetcode.com/problems/flatten-binary-tree-to-linked-list
// Flatten Binary Tree to Linked List


// Approach - 1 (Recursive)
// T.C = O(N)
// S.C = O(N)
class Solution {
public:
    TreeNode* prev = NULL;
    void flatten(TreeNode* root) {
        if(root == NULL) {
            return;
        }
        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};





// Approach - 2 (Morris Traversal)
// T.C = O(N)
// S.C = O(1)
class Solution {
public:
    void flatten(TreeNode* root) {
        while(root != NULL){
            if(root->left == NULL){
               root = root->right;
            } else {
                TreeNode* temp = root->left;
                while(temp->right){
                  temp = temp->right;
                }
                temp->right = root->right;
                root->right = root->left;
                root->left = NULL;
                root = root->right;
            }
        }
    }
};
