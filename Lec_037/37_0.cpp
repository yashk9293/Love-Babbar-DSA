// Question Link :- https://leetcode.com/problems/subsets/
// Subsets (Power Set, i.e., subsequence)

// T.C = O(2^n)
// S.C = O(n) to store each subset
// The recursion stack space complexity is O(N) , the maximum depth of the recursion is N
class Solution {
    private:
    void solve(vector<int>& nums, int i, vector<vector<int>>& ans, vector<int> output) {
        // base case
        if(i>=nums.size()) {
            ans.push_back(output);
            return;
        }
        // exclude
        solve(nums, i+1, ans, output);

        // include
        output.push_back(nums[i]);
        solve(nums, i+1, ans, output);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums, 0, ans, output);
        return ans;
    }
};




// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]


// Input: nums = [0]
// Output: [[],[0]]
