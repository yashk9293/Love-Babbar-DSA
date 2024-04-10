// Question Link :- https://www.codingninjas.com/studio/problems/design-a-stack-that-supports-getmin-in-o-1-time-and-o-1-extra-space_842465
// Design a stack that supports getMin() in O(1) time and O(1) extra space

// SPECIAL STACK


// S.C = O(1)
#include<stack>
#include<limits.h>
class SpecialStack {
    // Define the data members.
	stack<int> s;
    int mini = INT_MAX;
    /*----------------- Public Functions of SpecialStack -----------------*/
    public:
        
    void push(int data) {
        //for first element
        if(s.empty()) {
            s.push(data);
            mini = data;
        }
        else {
         	if(data < mini) {
                s.push(2*data - mini);
                mini = data;
            }   
            else {
                s.push(data);
            }
        }
    }

    int pop() {
        if(s.empty()){
            return -1;
        }
        int curr = s.top();
        s.pop();
        if(curr > mini) {
            return curr;
        }
        else {
            int prevMin = mini;
            int val = 2*mini - curr;
            mini = val;
            return prevMin;
        }
    }

    int top() {
        if(s.empty()) {
            return -1;
        }
        int curr = s.top();
        if(curr < mini) {
            return mini;
        }
        else {
            return curr;
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if(s.empty()) {
            return -1;
        }
        return mini;
    }
};