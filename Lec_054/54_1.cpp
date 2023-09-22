// Implementation of Stack using array

#include<iostream>
#include<stack>
using namespace std;

class Stack {
    //properties
    public:
        int *arr;
        int top;
        int size;

    // behaviour
    Stack(int size) {
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    //O(1)
    void push( int element) {
        if(size - top > 1) {
            top++;
            arr[top] = element;
        }
        else {
            cout << "Stack OverFlow" << endl;
        }
    }

    //O(1)
    void pop() {
        if(top >=0 ) {
            top--;
        }
        else {
            cout << "Stack UnderFlow" << endl;
        }
    }

    //O(1)
    int peek() {
        if(top >=0 )
            return arr[top];
        else {
            cout << "Stack is Empty" << endl;
            return -1;
        }
    }

    //O(1)
    bool isEmpty() {
        if( top == -1) {
            return true;
        }
        else {
            return false;
        }
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

    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;

    if(st.isEmpty()) {
        cout << "Stack is Empty mere dost " << endl;
    }
    else {
        cout << "Stack is not Empty mere dost " << endl;
    }

    return 0;
}


// Output :-

// Stack OverFlow
// 43
// 22
// 44
// 43
// Stack is not Empty mere dost 