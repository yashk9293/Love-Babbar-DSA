// Question Link :- https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1
// Insert an Element at the Bottom of a Stack

// Approach - 1 (Recursive)
// T.C = O(n)
// S.C = O(1) exluding the O(n) system stack used in recursion
class Solution{
public:
    void solve(stack<int> &st, int x) {
        if(st.empty()) {
            st.push(x);
            return;
        }
        int currTop = st.top();
        st.pop();
        solve(st, x);
        st.push(currTop);
    }
    stack<int> insertAtBottom(stack<int> st,int x){
        solve(st, x);
        return st;
    }
};





// Approach - 2 (Iterative)
// T.C = O(n)
// S.C = O(n)
class Solution{
public:
    stack<int> insertAtBottom(stack<int> st,int x){
        stack<int>temp;
        while(!st.empty()){
            temp.push(st.top());
            st.pop();
        } 
        st.push(x);
        while(!temp.empty()){   
            st.push(temp.top());
            temp.pop();
        }
        return st;
    }
};
