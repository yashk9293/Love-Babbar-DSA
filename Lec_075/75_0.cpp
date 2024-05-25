// Question Link :- https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
// Kth smallest element (codestorywithMIK - Lec 12)

// Approach - 1
// T.C = O(nlogn)
// sort the array : O(nlogn)
// return the arr[k-1] : O(1)

// Approach - 2
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        priority_queue<int> maxHeap;
        for(int i=l; i<=r; i++) {
            maxHeap.push(arr[i]);
            if(maxHeap.size() > k) {
                maxHeap.pop();
            }
        }
        return maxHeap.top();
    }
};

/*
****NOTE : we are finding smallest element using max heap, so similarly for finding kth largest
           element we will use min heap.
*/
