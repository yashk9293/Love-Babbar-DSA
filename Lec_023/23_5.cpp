// Question Link :- https://leetcode.com/problems/search-a-2d-matrix-ii/
// Search in a 2D Matrix II

// T.C = O(m+n)
// S.C = O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = n-1;
        while(i < m && j>=0 ) {
            if(matrix[i][j] == target) {
                return true;
            }
            if(matrix[i][j] < target){
                i++;
            } else if(matrix[i][j] > target) {
                j--;
            }
        }
        return false;
    }
};
