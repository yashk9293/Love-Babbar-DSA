// Question Link :- https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
// Check if Array Is Sorted and Rotated

// T.C = O(N)
// S.C = O(1)
class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=1; i<n; i++) {
            if(nums[i-1] > nums[i]) {
                count++;
            }
        }
        if(nums[n-1]>nums[0]) {
            count++;
        }

        return count<=1;
    }
};


//            _______
//           |       |
// case 1 :  1 2 3 4 5      1 pair exist for given condition in sorted array

// case 2 :  4 5 1 2 3      1 pair exist for given condition in rotated array (prev ques)
//             |_|

//                  _
//                 | |
// case 3 :  4 7 8 5 2 2          more than 1 pair exists for normal unsorted array
//               |_|


// case 4 :  2 2 2 2 2        0 pair exist for same elements array


// therefore return count<=1, either it could be 0 or 1





// Input: nums = [3,4,5,1,2]
// Output: true

// Input: nums = [2,1,3,4]
// Output: false

// Input: nums = [1,2,3]
// Output: true
