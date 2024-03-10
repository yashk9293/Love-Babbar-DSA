// Question Link :- https://www.codingninjas.com/studio/problems/find-k-th-smallest-element-in-bst_1069333
// Find K-th smallest Element in BST

// Approach - 1
// T.C = O(n)
// S.C = O(h)
int solve(BinaryTreeNode<int>* root, int k, int &i) {
    if(root == NULL) {
        return -1;
    }
    // L
    int left = solve(root->left, k, i);

    if(left != -1) {
        return left;
    }
    // N
    i++;
    if(i==k) {
        return root->data;
    }

    // R
    return solve(root->right, k, i);
}

int kthSmallest(BinaryTreeNode<int>* root, int k) {
    int i=0;
    int ans = solve(root, k, i);
    return ans;
}



// Approach -2
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
  
// Return the Kth smallest element in the given BST
int KthSmallestElement(Node *root, int K) { 
    vector<int> ans;
    inorderTraversal(root,ans);
    if(ans.size() < K) {
        return -1;
    }

    return ans[K-1];
}