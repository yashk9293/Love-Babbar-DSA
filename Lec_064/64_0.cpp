// Question Link :- https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal
// Binary Tree Zigzag Level Order Traversal (Striver)

// T.C = O(N) -> each element is enqueued and dequeued only once
// S.C = O(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;
        while(!q.empty()) {
            int size = q.size();
            vector<int> level(size);  // size dena imp hai, kyuki level[i] se element daal rhe hai, push_back hota toh size jaruri nhi tha
            for(int i=0; i<size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if(leftToRight) {
                    level[i] = node->val;
                } else {
                    level[size-i-1] = node->val;
                }
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            ans.push_back(level);
            leftToRight = !leftToRight;
        }
        return ans;
    }
};
