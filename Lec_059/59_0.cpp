// Question Link :- https://leetcode.com/problems/min-stack/
// Min Stack (Aditya Verma)

// Method - 1 (using 2 stacks)
// T.C = O(1)
// S.C = O(2n)
// Cons: Extra O(n) space
class MinStack {
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x) {
	    s1.push(x);
	    if (s2.empty() || x <= s2.top()) {
            s2.push(x);
        }	    
    }
    void pop() {
        if(s1.size() == 0) {
            return;
        }
        int a = s1.top();
        s1.pop();
	    if (a == s2.top()) {
            s2.pop();
        }
    }
    int top() {
	    return s1.top();
    }
    int getMin() {
	    return s2.top();
    }
};




// Method - 2 (using 1 stack)
// T.C = O(1)
// S.C = O(n)
class MinStack {
private:
    stack<pair<int,int>> st;
public:
    MinStack() {
                
    }
    
    void push(int val) {
        if (st.empty()) {
            st.push({val,val});
        }
        else {
            st.push({val, min(st.top().second, val)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};
