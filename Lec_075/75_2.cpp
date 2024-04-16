// Question Link :- https://practice.geeksforgeeks.org/problems/is-binary-tree-heap/1
// Is Binary Tree Max Heap

// T.C = O(n)
// S.C = O(n)
class Solution {
  public:
    int countNodes(Node* root) {
        if(root == NULL) {
            return 0;
        }

        int left = countNodes(root->left);
        int right = countNodes(root->right);

        return 1 + left + right;
    }
  
    bool isCBT(Node* root, int index, int cnt) {
        if(root == NULL) {
            return true;
        }

        if(index >= cnt) {
            return false;
        }

        bool left = isCBT(root->left, 2*index + 1, cnt);
        bool right = isCBT(root->right, 2*index + 2, cnt);

        return left && right;
    }
    
    bool isMaxOrder(Node* root) {
        if(root == NULL) {
            return true;
        }
        // no child is present
        if(root->left == NULL && root->right == NULL) {
            return true;
        }
        // left child present
        if(root->right == NULL) {
            return (root->data) > (root->left->data);
        }
        // both the child present
        else {
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);

            return (left && right && (root->data > root->left->data && root->data > root->right->data));
        }
    }
    
    bool isHeap(struct Node* tree) {
        int index=0;
        int totalCount = countNodes(tree);
        if(isCBT(tree, index, totalCount) && isMaxOrder(tree)) {
            return true;
        }
        else {
            return false;
        }
    }
};