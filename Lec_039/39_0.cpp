// Question Link :- https://leetcode.com/problems/permutations/description/
// Permutations


// Approach - 1 (Swaping Elements)
// T.C = O(N! x N)
// S.C = O(1)
class Solution {
    private:
    void solve(int index, vector<int> &nums, vector<vector<int>>& ans) {
        if(index == nums.size()) {
            ans.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++) {
            swap(nums[index], nums[i]);
            solve(index+1, nums, ans);
            // backtracking
            swap(nums[index], nums[i]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;
    }
};





// Approach - 2 (A very general Backtracking pattern which can help solve subsets, Subsets II, Permutations, Permutations II,  Combination Sum, Combination Sum II as well.)
// T.C = O(N! x N)
// S.C = O(n)
class Solution {
    private:
    void solve(vector<int> &temp, vector<int> &nums, vector<vector<int>>& ans, unordered_set<int> &st) {
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i=0; i<nums.size(); i++) {
            if(st.find(nums[i]) == st.end()) {
                temp.push_back(nums[i]);
                st.insert(nums[i]);

                solve(temp, nums, ans, st);

                st.erase(nums[i]);
                temp.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        unordered_set<int> st;
        solve(temp, nums, ans, st);
        return ans;
    }
};
