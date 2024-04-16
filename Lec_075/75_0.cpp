// Question Link :- https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1
// Kth smallest element

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
        priority_queue<int> Heap;
        for(int i =0; i<k; i++) {
            Heap.push(arr[i]);
        }
        
        for(int i=k; i<=r; i++) {
            if(arr[i]<Heap.top()) {
                Heap.pop();
                Heap.push(arr[i]);
            }
        }
        return Heap.top();
    }
};

/*
****NOTE : we are finding smallest element using max heap, so similarly for finding kth largest
           element we will use min heap.
*/
