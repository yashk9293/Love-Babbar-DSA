// Question Link :- https://www.codingninjas.com/studio/problems/next-smaller-element_1112581
// Next Smaller Element (Aditya Verma)

#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n){
    vector<int> vec;
    stack<int> st;
    for (int i = n-1; i >= 0; i--) {      // right to left
        if (st.size() == 0) {
            vec.push_back(-1);
        }
        else if (st.size() > 0 && st.top() < arr[i]) {
            vec.push_back(st.top());
        }
        else if (st.size() > 0 && st.top() >= arr[i]) {
            while (st.size() > 0 && st.top() >= arr[i]) {
                st.pop();
            }
            if (st.size() == 0) {
                vec.push_back(-1);
            } else {
                vec.push_back(st.top());
            }
        }
        st.push(arr[i]);
    }
    reverse(vec.begin(), vec.end());
    return vec;
}