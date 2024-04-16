// Question Link :- https://leetcode.com/problems/kth-largest-element-in-an-array
// Kth Largest Element in an Array

// T.C = O(nlogn)
// S.C = O(n)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //the smaller the earlier to be popped
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int num : nums){
            pq.push(num);
            if(pq.size() > k){
                pq.pop();
            }
        }
        //the smallest in top k elements
        return pq.top();
    }
};











int KthLargest(vector<int> arr, int K) {
    priority_queue<int, vector<int>, greater<int> > Heap;

    for(int i=0; i<K; i++) {
        Heap.push(arr[i]);
    }

    for(int i=K; i<arr.size(); i++) {
        if(arr[i] > Heap.top()) {
            Heap.pop();
            Heap.push(arr[i]);
        }
    }

    return Heap.top();
}