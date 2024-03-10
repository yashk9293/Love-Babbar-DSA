// Question Link :- https://www.codingninjas.com/studio/problems/validate-bst_799483
// Partial BST

// -The left subtree of a node contains only nodes with data less than and equal to the node's data.
// -The right subtree of a node contains only nodes with data less than and equal to the node's data.
// -Both the left and right subtrees must also be the partial binary search trees.

// Approach - 1
// T.C = O(n)
// S.C = O(n)
// Travel the BST in the inorder traversal, and store the elements in an array or vector, and check whether
// they are in ascending order. If yes than return true else return false.

// Approach - 2
// T.C = O(n)
// S.C = O(1)

bool isBST(BinaryTreeNode<int> *root, int min, int max) {
    // base case
    if(root == NULL) {
        return true;
    }

    if(root->data >= min && root->data <= max) {
        bool left = isBST(root->left, min, root->data);
        bool right = isBST(root->right, root->data, max);
        return left && right;
    }
    else {
        return false;
    }
}


bool validateBST(BinaryTreeNode<int> *root) {
    bool ans = isBST(root, INT_MIN, INT_MAX);
    return ans;
}