// Question Link :- https://www.codingninjas.com/studio/problems/validate-bst_799483
// Partial BST

// Approach - 1
// T.C = O(n)
// S.C = O(n)
void solve(BinaryTreeNode<int>* root, vector<int>&ans) {
    if(root == NULL) {
        return;
    }
    solve(root->left, ans);
    ans.push_back(root->data);
    solve(root->right, ans);
}

bool validateBST(BinaryTreeNode<int> *root) {
    vector<int>ans;
    solve(root, ans);
    for(int i=0; i<ans.size()-1; i++) {
        if(ans[i] >= ans[i+1]) {
            return false;
        }
    }
    return true;
}



// Approach - 2
// T.C = O(n)
// S.C = O(1)
bool isBST(BinaryTreeNode<int> *root, long mini, long maxi) {
    if(root == NULL) {
        return true;
    }
    if(root->data < mini || root->data > maxi) {
        return false;
    }
    bool left = isBST(root->left, mini, root->data);
    bool right = isBST(root->right, root->data, maxi);
    return left && right;
}

bool validateBST(BinaryTreeNode<int> *root) {
    return isBST(root, LLONG_MIN, LLONG_MAX);
}
