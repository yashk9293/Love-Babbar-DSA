#include<iostream>
#include<queue>
using namespace std;

int main() {
    cout << (-1)%1<< endl;
    deque<int> d;

    d.push_front(12);
    d.push_back(14);

    cout << d.front() << endl;
    cout << d.back() << endl;

    d.pop_front();
    
    cout << d.front() << endl;
    cout << d.back() << endl;
    d.pop_back();

    if(d.empty()) {
        cout << "queue is empty" << endl;
    }
    else {
        cout << "queue is not empty " << endl;
    }

    return 0;
}


// Output :-
// 0
// 12
// 14
// 14
// 14
// queue is empty