// Max and Min Heap By Priority Queue

#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> maxHeap;
    maxHeap.push(52);
    maxHeap.push(50);
    maxHeap.push(54);
    maxHeap.push(40);
    maxHeap.push(35);
    maxHeap.push(65);
    cout << "Top element : " << maxHeap.top() << endl;
    maxHeap.pop();
    cout << "Top element : " << maxHeap.top() << endl;
    maxHeap.pop();
    maxHeap.pop();
    cout << "Top element : " << maxHeap.top() << endl;
    if(maxHeap.empty()) {
        cout << "Max Heap is empty!" << endl;
    }

    priority_queue<int, vector<int>, greater<int> > minHeap;
    minHeap.push(52);
    minHeap.push(50);
    minHeap.push(54);
    minHeap.push(40);
    minHeap.push(35);
    minHeap.push(65);
    cout << "\nTop element : " << minHeap.top() << endl;
    minHeap.pop();
    cout << "Top element : " << minHeap.top() << endl;
    minHeap.pop();
    minHeap.pop();
    cout << "Top element : " << minHeap.top() << endl;
    if(minHeap.empty()) {
        cout << "Min Heap is empty!" << endl;
    }

    return 0;
}



// Output :-
// Top element : 65
// Top element : 54
// Top element : 50

// Top element : 35
// Top element : 40
// Top element : 52