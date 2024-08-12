// Question Link :- https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1
// Left View of Binary Tree

// T.C = O(N)
// For a balanced binary tree, the height is log2N but in the worst case when the tree is skewed, the complexity becomes O(N).

// S.C = O(N)
// The size of this result vector is proportional to the height of the Binary Tree which will be log2N when the tree is balanced and O(N) in the worst case of a skewed tree.


// Approach - 1 (Pre Order Traversal)
void solve(Node *root, vector<int> &ans, int level) {
    if (root == NULL) {
        return;
    }
    if (level == ans.size()) {
        ans.push_back(root->data);
    }
    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}

vector<int> leftView(Node *root) {
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}





// Approach - 2 (Level Order Traversal)
vector<int> leftView(Node *root) {
   vector<int> ans;   // modification 1
    if(root == NULL) {
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        ans.push_back(q.front()->data);  // modification 2
        for(int i=0; i<size; i++) {
            Node *node = q.front();
            q.pop();
            if(node->left) {
                q.push(node->left);
            }
            if(node->right) {
                q.push(node->right);
            }
        }
    }
    return ans;
}
