// Question Link :- https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
// Sum of nodes on the longest path from root to leaf node

// T.C = O(n)
// S.C = O(height)
class Solution {
public:
    void solve(Node *root, int len, int &maxLen, int sum, int &maxSum) {
        if(root == NULL) {
            if(len > maxLen) {
                maxLen=len;
                maxSum=sum;
            }
            else if(len == maxLen) {
                maxSum=sum;
            }
            return;
        }
        sum = sum + root->data;
        
        solve(root->left, len+1, maxLen, sum, maxSum);
        solve(root->right, len+1, maxLen, sum, maxSum);
    }
    
    int sumOfLongRootToLeafPath(Node *root) {
        int len=0;
        int maxLen=0;
        
        int sum=0;
        int maxSum=0;
        solve(root, len, maxLen, sum, maxSum);
        
        return maxSum;
    }
};