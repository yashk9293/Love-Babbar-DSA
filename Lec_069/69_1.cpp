// Question Link :- https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
// Convert Sorted Array to Binary Search Tree

class Solution {
public:
    TreeNode* buildTree(vector<int> &nums,int s, int e){
        if(nums.size()==0) {
            return NULL;
        }
        if(s>e) {
            return NULL;
        }
        int mid = (s+e)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, s, mid-1);
        root->right = buildTree(nums, mid+1, e);

        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildTree(nums, 0, nums.size()-1);
    }
};