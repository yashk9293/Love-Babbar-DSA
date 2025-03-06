// Question Link :- https://www.naukri.com/code360/problems/stack-implementation-using-array_3210209
// Stack Implementation Using Array

// T.C = O(N)
// S.C = O(N)

#include<iostream>
#include<stack>
using namespace std;

class Stack {
private:
    int *arr;        // Dynamic array to store stack elements
    int topIndex;    // Index of the top element
    int capacity; 

public:
    Stack(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        topIndex = -1;
    }

    void push(int num) {
        if (isFull()) {
            return;
        }
        topIndex++;
        arr[topIndex] = num;
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }
        int topElement = arr[topIndex];
        topIndex--;
        return topElement;
    }

    int top() {
        if (isEmpty()) {
            return -1;
        }
        return arr[topIndex];
    }

    int isEmpty() {
        return topIndex == -1;
    }

    int isFull() {
        return topIndex == capacity - 1;
    }

    ~Stack() {
        delete[] arr;
    }
};



int main() {
    Stack st(5);

    st.push(22);
    st.push(43);
    st.push(44);
    st.push(22);
    st.push(43);
    st.push(44);

    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;

    if(st.isEmpty()) {
        cout << "Stack is Empty mere dost " << endl;
    }
    else {
        cout << "Stack is not Empty mere dost " << endl;
    }

    return 0;
}


// Output :-

// 43
// 22
// 44
// 43
// Stack is not Empty mere dost







// Approach - 2
// Using vectors
class Stack {
    vector<int> arr;
    int capacity;
    
public:
    
    Stack(int capacity) {
        this->capacity = capacity;
    }

    void push(int num) {
        if(isFull()) {
            return;
        }
        arr.push_back(num);
    }

    int pop() {
        if(isEmpty()) {
            return -1;
        }
        int topElement = arr.back();
        arr.pop_back();
        return topElement;
    }
    
    int top() {
        if (isEmpty()) {
            return -1;
        }
        return arr.back();
    }
    
    int isEmpty() {
        return arr.empty();
    }
    
    int isFull() {
        if(arr.size() == capacity) {
            return 1;
        }
        return 0;
    }
};
