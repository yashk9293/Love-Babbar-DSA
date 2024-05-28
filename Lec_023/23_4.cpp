// Question Link :- https://leetcode.com/problems/search-a-2d-matrix/
// Search a 2D matrix

// You are given an m x n integer matrix matrix with the following two properties:
// i)  Each row is sorted in non-decreasing order.
// ii) The first integer of each row is greater than the last integer of the previous row.

// Approach - 1 (same code as Search a 2D matrix II)
// T.C = O(m+n)
// S.C = O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = n-1;
        while(i < m && j >= 0) {
            if(matrix[i][j] == target) {
                return true;
            }
            if(matrix[i][j] < target) {
                i++;
            } else if(matrix[i][j] > target) {
                j--;
            }
        }
        return false;
    }
};






// Approach - 2
// T.C = O(log(m*n))
// S.C = O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        //apply binary search:
        int low = 0, high = n * m - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            int row = mid / m, col = mid % m;
            if (matrix[row][col] == target) {
                return true;
            }
            else if (matrix[row][col] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return false;
    }
};



// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false
