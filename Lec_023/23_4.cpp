// Question Link :- https://leetcode.com/problems/search-a-2d-matrix/
// Search a 2D matrix

// You are given an m x n integer matrix matrix with the following two properties:
// i)  Each row is sorted in non-decreasing order.
// ii) The first integer of each row is greater than the last integer of the previous row.

#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int start = 0;
        int end  = row*col-1;
        
        int mid = start + (end-start)/2;    // this is mid element of 1D array
        
        while(start<=end) {
            int element = matrix[mid/col][mid%col];  // to find the mid element of 2D array
            if(element == target) {
                return 1;
            }
            if(element < target) {
                start = mid+1;
            }
            else {
                end = mid-1;
            }
             mid = start + (end-start)/2;    
        }
        return 0;
    }
};



// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false