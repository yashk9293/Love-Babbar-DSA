// Question Link :- https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
// Two Sum IV - Input is a BST


// Approach - 1 (Brute Force)
// T.C = O(n^2)
// S.C = O(h)
// travel for every node

// node, target-node => left, right
// node->left, taget-node->left => left, right
// node->right, target-node->right => left, right
// .
// .





// Approach - 2
// T.C = O(N)
// S.C = O(N)
class Solution {
public:
    void inOrder(TreeNode* root, vector<int>& ans) {
        if(root == NULL) {
            return;
        }
        inOrder(root->left, ans);
        ans.push_back(root->val);
        inOrder(root->right, ans);
    }

    bool findTarget(TreeNode* root, int k) {
        if(root == NULL) {
            return false;
        }
        vector<int> ans;
        inOrder(root, ans);

        /*

        unordered_map<int, int> mp;
        for(auto num : ans) {
            if(mp.find(k-num) != mp.end()) {
                return true;
            }
            mp[num]++;
        }
        return false;
        
        */

        int i=0, j= ans.size()-1;
        while(i < j) {
            int sum = ans[i] + ans[j];
            if(sum == k) {
                return true;
            }
            if(sum > k) {
                j--;
            } 
            else {
                i++;
            }
        }
        return false;
    }
};
