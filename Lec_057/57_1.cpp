// Question Link :- https://leetcode.com/problems/maximal-rectangle/description/
// Maximal Rectangle 


// Brute Force
// T.C = O((n^2)*m)
// Reason: Calling 'calculateMAH' function for 'm' times and O(n^2) for Using 2 Nested 'for' loop in 'calculateMAH'
// S.C = O(1)
class Solution{
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        vector<int> left(n, -1);
        vector<int> right(n, n);
        // nearest smaller to right
        for (int i = 0; i < n; i++) {
            for (int j = i-1; j >= 0; j--) {
                if(heights[j] < heights[i]) {
                    left[i] = j;
                    break;
                }
            }
        }
        // nearest smaller to right
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if(heights[j] < heights[i]) {
                    right[i] = j;
                    break;
                }
            }
        }

        int mah = INT_MIN;
        for (long long i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int length = heights[i];
            mah = max(m, width * length);       // taking max after finding area
        }
        return mah;
    }

    int maximalRectangle(vector<vector<char>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size(), result = 0;
        vector<int> histogram(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1')
                    histogram[j] += 1;
                else
                    histogram[j] = 0;
            }
            result = max(result, largestRectangleArea(histogram));
        }
        return result;
    }
};