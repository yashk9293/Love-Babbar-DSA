// Question Link :- https://leetcode.com/problems/rotate-image/description/
// Rotate matrix by 90 degree

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        //tranaspose
        for(int i =0; i<matrix.size();i++){
            for(int j =0 ; j<i ; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //reverse
        for(int i=0;i<matrix.size();i++){  
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]]


// Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
// Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]