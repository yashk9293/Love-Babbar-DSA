// Question Link :- https://leetcode.com/problems/permutations/description/
// Permutations

// T.C = O(N! x N)
// S.C = O(1)
class Solution {
    private:
    void solve(vector<int> nums, vector<vector<int>>& ans, int index) {
        if(index>=nums.size()) {
            ans.push_back(nums);
            return;
        }

        for(int j=index; j<nums.size(); j++) {
            swap(nums[index], nums[j]);
            solve(nums, ans, index+1);
            // backtracking
            swap(nums[index], nums[j]); // the code will work even we do not use it as because each time 
//                                         vector nums is passed by value  so  in every new call a new vector 
//                                         will be created  so even  when the nums vector is changed in future 
//                                         recursive calls it will not affect the previous nums vector.
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index = 0;
        solve(nums, ans, index);
        return ans;
    }
};
