// Question Link :- https://www.codingninjas.com/studio/problems/median-in-a-stream_975268
// Median in a stream

// Approach - 1 (naive approach)
// step 1 : sort the array using insertion sort - O(n^2)
// step 2 : using binary search put new element in the array - O(n)
// step : print the median of the array - O(1)
//T.C = O(n^2) + O(n) + O(1) = O(n^2)





// Approach - 2
// T.C = O(n logn)
// S.C = O(n)
#include<bits/stdc++.h>
int signum(int a, int b) {
    return (a==b) ? 0 : (a>b ? 1 : -1);
}

// int signum(int a, int b) {
//     if(a==b) {
//         return 0;
//     }
//     else if(a>b) {
//         return 1;
//     }
//     else {
//         return -1;
//     }
// }

void callMedian(int element, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int> > &minHeap, int &median) {
    switch(signum(maxHeap.size(), minHeap.size())) {
        case 0 :
            if(element > median) {
                minHeap.push(element);
                median = minHeap.top();
            } 
            else {
                maxHeap.push(element);
                median = maxHeap.top();
            }
            break;

        case 1 : 
            if(element > median) {
                minHeap.push(element);
            } 
            else {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(element);
            }
            median = (minHeap.top() + maxHeap.top()) / 2;
            break;
        
        case -1 :
            if(element > median) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(element);
            } 
            else {
                maxHeap.push(element);
            }
            median = (minHeap.top() + maxHeap.top()) / 2;
            break;
    }
}

vector<int> findMedian(vector<int>& arr, int n) {
    vector<int> ans;
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;

    int median = 0;

    for(int i=0; i<n; i++) {
        callMedian(arr[i], maxHeap, minHeap, median);
        ans.push_back(median);
    }
    return ans;
}