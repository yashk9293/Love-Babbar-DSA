// Question Link :- https://practice.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
// Vertical Traversal of Binary Tree (Striver)

// NOTE : If there are multiple nodes passing through a vertical line, then they should be printed 
// as they appear in level order traversal of the tree, that's why we use 'vector' in the map..



// T.C = O(NlogN) where N represents the number of nodes in the Binary Tree.
// For BFS Traversal -> O(N) and for insertion into map O(logN). So O(NlogN)

// The outer loop runs for each unique vertical index (let's say there are V such verticals) -> O(V)

// The inner loop runs for each unique level index within a vertical (lets say there are
// L levels per vertical on average) -> O(L)

// For each level, the multiset of node values is traversed. Since the multiset might store up to 
// N nodes, inserting them into the vector col takes  O(N) operations in the worst case.

// So O(V*L*N) ~ O(N) for traversing

// S.C = O(N + N/2) -> map + queue(the maximum level of the tree which can be O(N/2) in the worst case of a balanced tree)


class Solution {
    public:
    vector<int> verticalOrder(Node *root) {
        map<int, map<int, vector<int>>> mp;  // {vertical, level, multinodes}
        queue<pair<Node*, pair<int, int>>> q;  // {node, vertical, level}
        q.push({root, {0, 0}});  
        // BFS traversal
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            Node* temp = p.first;
            int x = p.second.first;  // vertical
            int y = p.second.second; // level
            mp[x][y].push_back(temp->data);  // mp[vertical][level] = nodes
            if(temp->left) {
                q.push({temp->left, {x-1, y+1}});
            }
            if(temp->right) {
                q.push({temp->right, {x+1, y+1}});
            }
        }
        vector<int> ans;
        for(auto x: mp) {  // x = int, map<int, multiset<int>>
            for(auto y: x.second) {  // x.second = map<int, multiset<int>> and y = int, multiset<int>
                // ans.insert(ans.end(), y.second.begin(), y.second.end());
                for(auto z : y.second) {  // y.second = multiset<int> and z = int
                    ans.push_back(z);
                }
            }
        }
        return ans;
    }
};
