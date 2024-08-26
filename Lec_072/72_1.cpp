// Question Link :- https://www.geeksforgeeks.org/problems/merge-two-bst-s/1
// Merge two BST 's

// step 1 : store the inorder of both the bst
// step 2 : merge two sorted arrays

// T.C = O(m+n)
// S.C = O(m+n)
class Solution {
  public:
    void inOrder(Node* root, vector<int>& ans) {
        if(root == NULL) {
            return;
        }
        inOrder(root->left, ans);
        ans.push_back(root->data);
        inOrder(root->right, ans);
    }
    
    vector<int> mergeArrays(vector<int> arr1, vector<int> arr2) {
        if(arr1.size() == 0 || arr2.size() == 0) {
            return (arr1.size()) ? arr1 : arr2;
        }
        int i=0, j=0;
        vector<int> solution;
    
        while(i<arr1.size() && j<arr2.size()) {
            if(arr1[i] < arr2[j]) {
                solution.push_back(arr1[i]);
                i++;
            } else {
                solution.push_back(arr2[j]);
                j++;
            }
        }
        while(i < arr1.size()) {
            solution.push_back(arr1[i]);
            i++;
        }
        while(j < arr2.size()) {
            solution.push_back(arr2[j]);
            j++;
        }
        return solution;
    }

    vector<int> merge(Node *root1, Node *root2) {
        vector<int> arr1;
        vector<int> arr2;
        inOrder(root1, arr1);
        inOrder(root2, arr2);
    
        return mergeArrays(arr1, arr2);
    }
};
