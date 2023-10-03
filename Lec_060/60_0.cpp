#include<iostream>
#include<queue>
using namespace std;

int main() {
    // create a queue
    queue<int> q;

    q.push(11);
    cout << "front of q is: " << q.front() << endl;
    q.push(15);
    cout << "front of q is: " << q.front() << endl;
    q.push(13);
    cout << "front of q is: " << q.front() << endl;

    cout << "size of queue is : " << q.size() << endl;

    q.pop();
    cout << "size of queue is : " << q.size() << endl;
    q.pop();
    q.pop();

    if(q.empty()) {
        cout << "Queue is empty " << endl;
    }
    else {
        cout << "queue is not empty " << endl;
    }

    return 0;
}



// Output :-

// front of q is: 11
// front of q is: 11
// front of q is: 11
// size of queue is : 3
// size of queue is : 2
// Queue is empty 