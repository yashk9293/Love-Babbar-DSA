// Question Link :- https://www.geeksforgeeks.org/problems/merge-sort/1
// MERGE SORT - STRIVER 

// Merge sort is a Recursive Algorithm that continuously splits the array in half until it cannot be further divided i.e., 
// the array has only one element left (an array with one element is always sorted). Then the sorted subarrays are merged 
// into one sorted array.

// it is faster than bubble, selection and insertion sort.


// T.C - O(N log(N))
// The time complexity of Merge Sort is O(Nlog(N)) in all 3 cases (worst, average, and best) as merge sort always divides 
// the array into two halves and takes linear time to merge two halves.

// Auxiliary Space: O(N), In merge sort all elements are copied into an auxiliary array. So N auxiliary space is required for 
// merge sort.

class Solution {
  public:
    void merge(vector<int> &arr, int low, int mid, int high) {
        vector<int> temp;
        int left = low;      // starting index of left half of arr
        int right = mid + 1;   // starting index of right half of arr
    
        while (left <= mid && right <= high) {
            if (arr[left] <= arr[right]) {
                temp.push_back(arr[left]);
                left++;
            }
            else {
                temp.push_back(arr[right]);
                right++;
            }
        }
        // if elements on the left half are still left //
        while (left <= mid) {
            temp.push_back(arr[left]);
            left++;
        }
        //  if elements on the right half are still left //
        while (right <= high) {
            temp.push_back(arr[right]);
            right++;
        }
    
        // transfering all elements from temporary to arr //
        for (int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    void mergeSort(vector<int> &arr, int low, int high) {
        if (low >= high) {
            return;
        }
        int mid = (low + high) / 2 ;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);  // merging sorted halves
    }
};
