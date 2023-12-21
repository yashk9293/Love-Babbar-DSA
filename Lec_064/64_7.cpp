// Question Link :- https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
// Diagonal Traversal of Binary Tree

vector<int> diagonal(Node *root) {
    queue<Node *> q;
    vector<int> ans;
    if (root == NULL) {
        return ans;
    }

    q.push(root);
    while (!q.empty()) {
        Node *temp = q.front();
        q.pop();
        while (temp) {
            if (temp->left) {
                q.push(temp->left);
            }
            ans.push_back(temp->data);
            temp = temp->right;
        }
    }
    return ans;
}