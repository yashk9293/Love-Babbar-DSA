// Question Link :- https://www.codingninjas.com/studio/problems/search-in-bst_1402878
// Search In BST

// T.C = O(n)
// S.C = O(h)

// Recursive way
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    if(root == NULL) {
        return false;
    }
    if(root->data == x) {
        return true;
    }
    else if(root->data > x) {
        return searchInBST(root->left, x);
    }
    else {
        return searchInBST(root->right, x);
    }
}




// Iterative way
bool searchInBST(BinaryTreeNode<int> *root, int x) {
    BinaryTreeNode<int> *temp =  root;
    while(temp != NULL) {
        if(temp->data == x) {
            return true;
        }
        if(temp->data > x) {
            temp = temp->right;
        }
        else {
            temp = temp->left;
        }
    }
    return false;
}