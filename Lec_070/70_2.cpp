// previous Ques

// Approach - 3 (Morris Traversal)
// T.C = O(n)
// S.C = O(1)
int morrisTraversal(BinaryTreeNode<int>* root, int k) {
    BinaryTreeNode<int>* curNode = root;

    while (curNode != NULL) {
        if (curNode->left == NULL) {
            k = k - 1;

            // If 'curNode' is 'k-th' smallest node
            if (k == 0) {
                return curNode->data;
            }
            curNode = curNode->right;
        } 
        else {
            BinaryTreeNode<int>* prev = curNode->left;

            // Find rightmost child node of 'curNode'
            while (prev->right != NULL && prev->right != curNode) {
                prev = prev->right;
            }
            // If rightmost node is leaf node then
            // Make a connection between rightmost node and 'curNode'
            if (prev->right == NULL) {
                prev->right = curNode;
                curNode = curNode->left;
            }
            else {
                prev->right = NULL;
                k = k - 1;
                if (k == 0) {
                    // If 'curNode' is 'k-th' smallest node
                    return (curNode->data);
                }
                curNode = curNode->right;
            }
        }
    }
    // If number of nodes less than 'k'
    return -1;
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    return morrisTraversal(root, k);
}