// Question Link :- https://practice.geeksforgeeks.org/problems/kth-ancestor-in-a-tree/1
// Kth Ancestor in a Tree

// T.C = O(n)
// S.C = O(height)
// the result vector stores the path from the root to the current node, which in the worst case (for a 
// skewed tree) will also store up to H elements.

// Approach - 1
void solve(Node* root, int node, vector<int> &ans, vector<int> &result) {
    if(root == NULL) {
        return;
    }
    if(root->data == node) {
        ans = result;
        return;
    }
    result.push_back(root->data);
    
    solve(root->left, node, ans, result);
    solve(root->right, node, ans, result);
    result.pop_back();
}

int kthAncestor(Node *root, int k, int node) {
    vector<int> ans, result;
    solve(root, node, ans, result);
    if(ans.size() < k) {
        return -1;
    }
    return ans[ans.size()-k];
}








// Approach - 2 (love babbar)
Node* solve(Node *root, int &k, int node) {
    // base case
    if(root == NULL) {
        return NULL;
    }
    if(root->data == node) {
        return root;
    }
    Node* leftAns = solve(root->left, k, node);
    Node* rightAns = solve(root->right, k, node);
    
    // wapas
    if(leftAns!= NULL && rightAns==NULL) {
        k--;
        if(k<=0) {
            // answer lock
            k=INT_MAX;
            return root;
        }
        return leftAns;
    }
    
    if(leftAns== NULL && rightAns!=NULL) {
        k--;
        if(k<=0) {
            // answer lock
            k=INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}

int kthAncestor(Node *root, int k, int node) {
    Node* ans = solve(root, k, node);
    if(ans==NULL || ans->data == node) {    // edge case (ans->data == node) as k always > 1 in question. 
        return -1;
    }
    else {
        return ans->data;
    }
}
