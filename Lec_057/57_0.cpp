// Question Link :- https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1
// The Celebrity Problem

// Brute Force
// T.C = O(N^2)
// S.C = O(N)
class Solution {
public:
    int celebrity(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<int> you_know_me(n, 0);
        vector<int> i_know_you(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                if (mat[i][j] == 1) {
                    i_know_you[i]++;
                    you_know_me[j]++;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            if (you_know_me[i] == n - 1 && i_know_you[i] == 0) {
                return i;
            }
        }
        return -1;
    }
};



// Optimized Approach (Using Stack)
// T.C = O(N)
// S.C = O(N)
class Solution {
public:
    int celebrity(vector<vector<int>> &mat) {
        int n = mat.size();
        stack<int> st;
        for (int i = 0; i < n; i++) {
            st.push(i);
        }

        while (st.size() > 1) {
            int x = st.top();
            st.pop();
            int y = st.top();
            st.pop();

            if (mat[x][y] == 0) {
                st.push(x);
            } else {
                st.push(y);
            }
        }

        int celebrity = st.top();

        for (int i = 0; i < n; i++) {
            if (i == celebrity) {
                continue;
            }
            // now check when it is -1
            // mtlb agar celebrity kisko jaanta ho to wo return -1 aur maan lo koi celebrity ko na jaanata ho phir bhi -1
            if (mat[celebrity][i] == 1 || mat[i][celebrity] == 0) {
                return -1;
            }
        }
        return celebrity;
    }
};



// Optimal Solution
// T.C = O(N)
// S.C = O(1)
class Solution {
public:
    int celebrity(vector<vector<int>> &mat) {
        int n = mat.size();
        int top = 0, down = n - 1;

        while (top < down) {
            if (mat[top][down] == 1) {
                top++;
            } else {
                down--;
            }
        }

        if (top != down) {
            return -1;
        }

        for (int i = 0; i < n; i++) {
            if (i == top) {
                continue;
            }
            if (mat[top][i] == 1 || mat[i][top] == 0) {
                return -1;
            }
        }
        return top;
    }
};
