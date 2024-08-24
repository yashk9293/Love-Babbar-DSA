// Question Link :- https://www.codingninjas.com/studio/problems/find-k-th-smallest-element-in-bst_1069333
// Find K-th smallest Element in BST


// Approach - 1 (Inorder)
// T.C = O(n)
// S.C = O(n)
void inorderTraversal(Node* root, vector<int> &ans) {
    if(root == NULL) {
        return;
    }
    inorderTraversal(root->left, ans);
    ans.push_back(root->data);
    inorderTraversal(root->right, ans);
}

int KthSmallestElement(Node *root, int K) { 
    vector<int> ans;
    inorderTraversal(root, ans);
    if(ans.size() < K) {
        return -1;
    }
    return ans[K-1];
}




// Approach - 2 (Recursion)
// T.C = O(n)
// S.C = O(1)
void solve(BinaryTreeNode<int>* root, int& k, int& ans) {
    if(root == NULL) {
        return;
    }
    solve(root->left, k, ans);
    k--;
    if(k == 0) {
        ans = root->data;
        return;
    }
    solve(root->right, k, ans);
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int ans = -1;
    solve(root, k, ans);
    if(ans == -1) {
        return -1;
    }
    return ans;
}
