// Question link :- https://www.codingninjas.com/studio/problems/normal-bst-to-balanced-bst_920472
// Normal BST To Balanced BST

// T.C = O(n)
// S.C = O(n)
void inOrder(TreeNode<int>* root, vector<int> &inOrderVal) {
    if(root == NULL) {
        return;
    }
    inOrder(root->left, inOrderVal);
    inOrderVal.push_back(root->data);
    inOrder(root->right, inOrderVal);
}

TreeNode<int>* inorderToBST(int start, int end, vector<int> &inOrderVal) {
    if(end-start < 0) {
        return NULL;
    }
    int mid = start + (end-start)/2;
    TreeNode<int>* temp = new TreeNode<int>(inOrderVal[mid]);

    temp->left = inorderToBST(start, mid-1, inOrderVal);
    temp->right = inorderToBST(mid+1, end, inOrderVal);

    return temp;
}

TreeNode<int>* balancedBst(TreeNode<int>* root) {
    vector<int>inOrderVal;
    inOrder(root, inOrderVal);
    return inorderToBST(0, inOrderVal.size()-1, inOrderVal);
}