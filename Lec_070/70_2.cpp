// previous Ques

// Approach - 3 (Morris Traversal)
// T.C = O(n)
// S.C = O(1)
int morrisTraversal(BinaryTreeNode<int>* root, int k) {
    BinaryTreeNode<int>* curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {
            k--;
            if (k == 0) {
                return curr->data;
            }
            curr = curr->right;
        } else {
            BinaryTreeNode<int>* temp = curr->left;
            while (temp->right != NULL && temp->right != curr) {  // Find rightmost child node of 'curr->left'
                temp = temp->right;
            }
            // If rightmost node is leaf node then Make a connection between rightmost node and 'curr'
            if (temp->right == NULL) {
                temp->right = curr;
                curr = curr->left;
            } else {
                temp->right = NULL;
                k--;
                if (k == 0) {
                    return curr->data;
                }
                curr = curr->right;
            }
        }
    }
    return -1;  // If number of nodes less than 'k'
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    return morrisTraversal(root, k);
}
