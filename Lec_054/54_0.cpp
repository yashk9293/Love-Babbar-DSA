// STACKS
// Reference - https://en.cppreference.com/w/cpp/container/stack

#include<iostream>
#include<stack>
using namespace std;

int main() {
    //creation of stack
    stack<int> s;

    //push operation
    s.push(2);
    s.push(3);

    //pop
    s.pop();

    cout << "Printing top element : " << s.top() << endl;

    if(s.empty()) {
        cout << "Stack is empty " << endl;
    }
    else {
        cout << "stack is not empty " << endl;
    }
    cout << "size of stack is : " << s.size() << endl;

    return 0;
}


// Output :-

// Printing top element : 2
// stack is not empty 
// size of stack is : 1