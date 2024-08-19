// Question Link :- https://www.geeksforgeeks.org/problems/burning-tree/1
// Burning Tree (Striver A2Z)

// T.C = O(N) + O(N) (if map has t.c. of logn, then t.c. = nlogn, and when map has t.c. of O(1), then t.c. = n)
// S.C = O(N) + O(N) = O(N)
class Solution {
  public:
    // Step 1: Create a parent map
    Node* addParent(Node* root, map<Node*, Node*>& mpp, int target) {
        Node* res= NULL;
        
        queue<Node*>q;
        q.push(root);
        while(!q.empty()) {
            Node* node = q.front();
            q.pop();
            if(node->data == target) {
                res = node;
            }
            if(node->left) {
                mpp[node->left] = node;
                q.push(node->left);
            }
            if(node->right) {
                mpp[node->right] = node;
                q.push(node->right);
            }
        }
        return res;
    }
    
    int minTime(Node* root, int target) {
        map<Node*, Node*> mpp;  // node -> parent
        Node* targetNode = addParent(root, mpp, target);
        
        int time = 0;
        
        // Step 2: Perform BFS from the target node
        map<Node*, bool> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;

        while (!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                Node* node = q.front();
                q.pop();
                
                if (node->left && !visited[node->left]) {
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if (node->right && !visited[node->right]) {
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if (mpp.find(node) != mpp.end() && !visited[mpp[node]]) {
                    q.push(mpp[node]);
                    visited[mpp[node]] = true;
                }
            }
            time++;
        }
        return time-1;
    }
};
