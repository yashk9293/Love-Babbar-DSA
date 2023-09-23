// Question Link :- https://www.codingninjas.com/studio/problems/minimum-cost-to-make-string-valid_1115770
// Minimum Cost To Make String Valid

#include <bits/stdc++.h>
int findMinimumCost(string str) {
    if (str.length() % 2 == 1) {
        return -1;
    }
    stack<char> st;
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (ch == '{') {
            st.push(ch);
        }
        else {
            if (!st.empty() && st.top() == '{') {
                st.pop();
            }
            else {
                st.push(ch);
            }
        }
    }
    // Now stack contains invalid expression
    int a = 0, b = 0;
    while (!st.empty()) {
        if (st.top() == '{') {
            a++;
        }
        else {
            b++;
        }
        st.pop();
    }
    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}




// Invalid String :-
// Type 1 - {{{{ ....
// Type 2 - }}}} ....
// Type 3 -  .... }}}{{{ ...