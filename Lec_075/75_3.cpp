// Question Link :- https://practice.geeksforgeeks.org/problems/merge-two-binary-max-heap0144/1
// Merge two binary Max heaps

// T.C = O(nlogn)
// S.C = O(n+m)
class Solution{
    public:
    // 0 based indexing
    void heapify(vector<int> &arr, int index, int size) {
        int largest = index;
        int left = 2*index + 1;
        int right = 2*index + 2;

        if(left < size && arr[largest] < arr[left]) {
            largest = left;
        }
        if(right < size && arr[largest] < arr[right]) {
            largest = right;
        }
        if(largest != index) {
            swap(arr[index], arr[largest]);
            heapify(arr, largest, size);
        }
    }

    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // we can store elements of vector b in vector a and heapify vector a.
        // or else we can create a new vector and store both vector elements in it and heapify the res vector.
        for(auto i : b) {
            a.push_back(i);
        }
        // 0 based indexing
        for(int i = a.size()/2 - 1; i >= 0; i--) {
            heapify(a, i, a.size());
        }
        return a;
    }
};
