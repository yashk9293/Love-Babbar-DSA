// Question Link :- https://www.codingninjas.com/studio/problems/flatten-bst-to-a-sorted-list_1169459
// Flatten BST To A Sorted List


// T.C = O(n)
// S.C = O(h)

// Approach - 1 (using vector<Node*>)
void inOrder(Node* root, vector<Node*>& ans) {
    if(root == NULL) {
        return;
    }

    inOrder(root->left, ans);
    ans.push_back(root);
    inOrder(root->right, ans);
}

void flattenBST(Node* &root) {
    if(root == NULL) {
        return;
    }

    vector<Node*> arr;
    inOrder(root, arr);

    for(int i=0; i<arr.size()-1; i++) {
        arr[i]->left = NULL;
        arr[i]->right = arr[i+1];
    }

    arr[arr.size()-1]->left = NULL;
    arr[arr.size()-1]->right = NULL;

    root = arr[0];
}





// Approach - 2 (using vector<int>)
void inOrder(TreeNode<int>* root, vector<int> &inOrderVal) {
    if(root == NULL) {
        return;
    }

    inOrder(root->left, inOrderVal);
    inOrderVal.push_back(root->data);
    inOrder(root->right, inOrderVal);
}

TreeNode<int>* flatten(TreeNode<int>* root) {
    vector<int>inOrderVal;
    inOrder(root, inOrderVal);

    int n = inOrderVal.size();
    TreeNode<int>* newRoot = new TreeNode<int>(inOrderVal[0]);
    TreeNode<int>* curr = newRoot;

    // 2nd Step
    for(int i=1; i<n; i++) {
        TreeNode<int>* temp = new TreeNode<int>(inOrderVal[i]);
        curr->left = NULL;
        curr->right = temp;
        curr=temp;
    }

    curr->left=NULL;
    curr->right=NULL;

    return newRoot;
}