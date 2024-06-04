// Question Link :- https://leetcode.com/problems/single-number/
// Single Number


// BRUTE FORCE APPROACH - to check every element if there count is 1 it means it unique and return that element
// T.C = O(n^2)
// S.C = O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count=0;
        for(int i=0; i<nums.size(); i++){
            count=0;
            for(int j=0; j<nums.size(); j++){
                if(nums[i] == nums[j]){
                    count++;
                }
            }
            if(count == 1){
                return nums[i];
            }
        }
        return -1;
    }
};



// ________________
// |  XOR Property |
// |_______________|
// |  a ^ a = 0    |
// |  0 ^ a = a    |
// |_______________|


// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr = 0;
        for(int i=0; i<nums.size(); i++) {
            xorr = xorr ^ nums[i];
        }
        return xorr;
    }
};

// Input :-
// 2 3 1 6 3 6 2
// 2 4 7 2 7
// 1 3 1 3 6 6 7 10 7

// Output :-
// 1
// 4
// 10
