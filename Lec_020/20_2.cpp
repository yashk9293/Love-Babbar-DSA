// Question Link :- https://leetcode.com/problems/move-zeroes/description/
// Move Zeroes

// T.C = O(N)
// S.C = O(1)

// Method - 1
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



// Method - 2
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZero = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[nonZero] = nums[i];
                nonZero++;
            }
        }
        while (nonZero < nums.size()) {
            nums[nonZero] = 0;
            nonZero++;
        }
    }
};
