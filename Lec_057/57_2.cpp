// Question Link :- https://leetcode.com/problems/maximal-rectangle/description/
// Question Link :- https://practice.geeksforgeeks.org/problems/max-rectangle/1
// Maximal Rectangle ((Aditya Verma))

// T.C = O((n*m))
// S.C = O(m)
class Solution{
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        vector<int> left, right;
        stack<pair<int, int>> s1, s2;
        // nearest smaller to right
        for (int i = 0; i < n; i++) {
            if (s1.size() == 0) {
                left.push_back(-1);
            }
            else if (s1.size() > 0 && s1.top().first < heights[i]) {
                left.push_back(s1.top().second);
            }
            else if (s1.size() > 0 && s1.top().first >= heights[i]) {
                while (s1.size() > 0 && s1.top().first >= heights[i]) {
                    s1.pop();
                }
                if (s1.size() == 0) {
                    left.push_back(-1);
                }
                else {
                    left.push_back(s1.top().second);
                }
            }
            s1.push({heights[i], i});
        }
        // nearest smaller to right
        for (int i = n - 1; i >= 0; i--) {
            if (s2.size() == 0) {
                right.push_back(n);
            }
            else if (s2.size() > 0 && s2.top().first < heights[i]) {
                right.push_back(s2.top().second);
            }
            else if (s2.size() > 0 && s2.top().first >= heights[i]) {
                while (s2.size() > 0 && s2.top().first >= heights[i]) {
                    s2.pop();
                }
                if (s2.size() == 0) {
                    right.push_back(n);
                }
                else {
                    right.push_back(s2.top().second);
                }
            }
            s2.push({heights[i], i});
        }
        reverse(right.begin(), right.end());       // reverse

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