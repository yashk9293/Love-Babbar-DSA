// Question Link :- https://leetcode.com/problems/find-pivot-index/
// Find Pivot Element

class Solution {
public:
    int pivotIndex(vector<int>& num) {
        int sum = 0;
        for(int i=0; i<num.size(); i++) {
            sum += num[i];
        }
    
        int left = 0;
        int right = sum;
    
        for(int i=0; i<num.size(); i++) {
            right = right - num[i];
            if(left == right) {
                return i;
            }
            else
                left = left + num[i];
        }
        return -1;
    }
};





// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11



// Input: nums = [1,2,3]
// Output: -1
// Explanation:
// There is no index that satisfies the conditions in the problem statement.



// Input: nums = [2,1,-1]
// Output: 0
// Explanation:
// The pivot index is 0.
// Left sum = 0 (no elements to the left of index 0)
// Right sum = nums[1] + nums[2] = 1 + -1 = 0
