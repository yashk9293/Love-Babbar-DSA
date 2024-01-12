// Question Link :- https://practice.geeksforgeeks.org/problems/construct-tree-1/1
// Construct Tree from Inorder & Preorder

// T.C = O(n^2)
// S.C = O(1)
class Solution {
    public:
    int findPosition(int in[], int element, int n) {
        for(int i=0; i<n; i++) {
            if(in[i] == element) {
                in[i]=0;       // Note :- imp point, othewise 1 test case not passing
                return i;
            }
        }
        return -1;
    }
    
    Node* solve(int in[],int pre[], int &index, int inorderStart, int inorderEnd, int n) {
        // base case
        if(index >= n || inorderStart > inorderEnd) {
            return NULL;
        }
        
        int element = pre[index++];
        Node* root = new Node(element);
        int position = findPosition(in, element, n);
        
        // recursive calls
        // left ki call pehle, right ki call baad me
        root->left = solve(in, pre, index, inorderStart, position-1, n);
        root->right = solve(in, pre, index, position+1, inorderEnd, n);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n) {
        int preOrderIndex = 0;
        Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n);
        return ans;
    }
};








// T.C = O(nlogn)
// S.C = O(n)
// in the above we have to rum findPosition func again n again for each iteration so we will use 
// map, so ultimately we will be gonna have O(1) time complexity here.
class Solution {
    public:
    void createMapping(int in[], map<int, int> &nodeToIndex, int n) {
        for(int i=0; i<n; i++) {
            nodeToIndex[in[i]]=i;
        }
    }
    
    Node* solve(int in[],int pre[], int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex) {
        // base case
        if(index >= n || inorderStart > inorderEnd) {
            return NULL;
        }
        
        int element = pre[index++];
        Node* root = new Node(element);
        int position = nodeToIndex[element];
        
        // recursive calls
        // left ki call pehle, right ki call baad me
        root->left = solve(in, pre, index, inorderStart, position-1, n, nodeToIndex);
        root->right = solve(in, pre, index, position+1, inorderEnd, n, nodeToIndex);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n) {
        int preOrderIndex = 0;
        map<int, int> nodeToIndex;
        // create nodes to index mapping
        createMapping(in, nodeToIndex, n);
        Node* ans = solve(in, pre, preOrderIndex, 0, n-1, n, nodeToIndex);
        return ans;
    }
};