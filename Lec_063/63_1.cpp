// Question Link :- https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1
// Diameter of a Binary Tree


// Approach - 1
// T.C = O(N^2)
// S.C = O(height)
class Solution {
  private:
    int height(struct Node* node){
        //base case
        if(node == NULL) {
            return 0;
        }
        int left = height(node ->left);
        int right = height(node->right);
        
        int ans = max(left, right) + 1;

        return ans;
    }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        if(root == NULL) {
            return 0;
        }
        
        int op1= diameter(root->left);
        int op2= diameter(root->right);
        int op3 = height(root-> left) + 1 + height(root-> right);
        
        int ans = max(op1, max(op2, op3));
        
        return ans;
    }
};





// Approach - 2
// T.C = O(N)
// S.C = O(height)
class Solution {
  public:
    pair<int, int> diameterFast(Node* root) {
        if(root == NULL) {
            pair<int,int> p = make_pair(0,0);
            return p;
        }

        pair<int, int> left = diameterFast(root->left);
        pair<int, int> right = diameterFast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + 1 + right.second;

        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;

        return ans;
    }

    int diameter(Node* root) {
        return diameterFast(root).first;
    }
};