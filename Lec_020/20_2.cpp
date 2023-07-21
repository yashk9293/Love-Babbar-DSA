// Question Link :- https://leetcode.com/problems/move-zeroes/description/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonzero=0;                           // in this index I want my first non-zero to be here
        for(int i=0; i<nums.size();i++) {
            if(nums[i]!=0) {
                swap(nums[i], nums[nonzero]);
                nonzero++;
            }
        }
    }
};