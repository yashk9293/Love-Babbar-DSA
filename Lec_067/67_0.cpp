// Question Link :- https://practice.geeksforgeeks.org/problems/burning-tree/1
// Burning Tree

// T.C = O(N) + O(N) (if map has t.c. of logn, then t.c. = nlogn, and when map has t.c. of O(1), then t.c. = n)
// S.C = O(N) + O(N) = O(N)
class Solution {
  public:
    // this function creates mapping as well as find and return target node
    Node* createParentMapping(Node* root, int target, map<Node*, Node*> &nodeToParent) {
        Node* res= NULL;
        
        queue<Node*>q;
        q.push(root);
        nodeToParent[root]=NULL;
        
        while(! q.empty()) {
            Node* front = q.front();
            q.pop();
            if(front->data == target) {
                res=front;
            }
            if(front->left) {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if(front->right) {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }
    
    int burnTree(Node* root, map<Node*, Node*> nodeToParent) {
        map<Node*, bool>visited;
        queue<Node*>q;
        q.push(root);
        visited[root]=true;
        
        int ans=0;
        while(!q.empty()) {
            bool flag = 0;
            int size=q.size();
            for(int i=0; i<size; i++) {
                //process neighbouring nodes
                Node* front=q.front();
                q.pop();
                
                if(front->left && !visited[front->left]) {
                    q.push(front->left);
                    visited[front->left]=1;
                    flag = 1;
                }
                if(front->right && !visited[front->right]) {
                    q.push(front->right);
                    visited[front->right]=1;
                    flag = 1;
                }
                if(nodeToParent[front] && !visited[nodeToParent[front]]) {
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]]=1;
                    flag = 1;
                }
            }
            if(flag == 1) {
                ans++;
            }
        }
        return ans;
    }
    
    int minTime(Node* root, int target) {
        // algo:
        // step 1: create nodeToParent mapping
        // step 2: find target node
        // step 3: burn the tree in min time
        
        map<Node*, Node*> nodeToParent;
        Node* targetNode = createParentMapping(root, target, nodeToParent);
        
        int ans=burnTree(targetNode, nodeToParent);
        
        return ans;
    }
};