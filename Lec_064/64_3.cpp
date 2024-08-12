// Question Link :- https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1
// Top View of Binary Tree

// T.C = O(N)
// S.C = O(N)
class Solution {
    public:
    vector<int> topView(Node *root) {
        vector<int> ans;
        if(root == NULL) {
            return ans;
        }
        map<int, int> mpp;  // {line, node->val}
        queue<pair<Node*, int>> q;  // {node, line}
        q.push({root, 0});
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            Node* node = it.first;
            int line = it.second;
            if(mpp.find(line) == mpp.end()) {
                mpp[line] = node->data;
            }
            if(node->left != NULL) {
                q.push({node->left, line - 1});
            }
            if(node->right != NULL) {
                q.push({node->right, line + 1});
            }
        }
        for(auto it : mpp) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
