// Question Link :- https://leetcode.com/problems/find-median-from-data-stream/
// Find Median from Data Stream

// Approach - 1 (naive approach)
// step 1 : sort the array using insertion sort - O(n^2)
// step 2 : using binary search put new element in the array - O(n)
// step : print the median of the array - O(1)
//T.C = O(n^2) + O(n) + O(1) = O(n^2)





// Approach - 2
// T.C = O(logN)
//    Constructor: O(1)
//    addNum: O(logN)
//    findMedian: O(1)
// S.C = O(N)

class MedianFinder {
public:
    priority_queue<int> left_maxHeap;
    priority_queue<int, vector<int>, greater<int>> right_minHeap;
    
    MedianFinder() {
    }
    void addNum(int num) {
        left_maxHeap.push(num);
        right_minHeap.push(left_maxHeap.top());
        left_maxHeap.pop();
        if (right_minHeap.size() > left_maxHeap.size()) {
            left_maxHeap.push(right_minHeap.top());
            right_minHeap.pop();
        }
    }
    double findMedian() {
        if (left_maxHeap.size() > right_minHeap.size()) {
            return left_maxHeap.top();
        }
        return (left_maxHeap.top() + right_minHeap.top()) / 2.0;
        // return (double)(left_maxHeap.top()+right_minHeap.top())/2;
    }
};
