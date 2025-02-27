// Question Link :- https://www.naukri.com/code360/problems/bubble-sort_980524
// Bubble Sort (Recursive)

// T.C = O(n^2)
// S.C = O(n)


#include <bits/stdc++.h> 
void bubbleSort(vector<int>& arr, int n) {
    if (n == 1) {
        return;
    }
    for (int i=0; i<n-1; i++) {
        if (arr[i] > arr[i+1]) {
            swap(arr[i],arr[i+1]);
        }
    }
    bubbleSort(arr, n - 1);
}



// Optimised
void bubbleSort(vector<int>& arr, int n) {
    if (n == 1) {
        return;
    }
    bool swapped = false;
    for (int i=0; i<n-1; i++) {
        if (arr[i] > arr[i+1]) {
            swap(arr[i],arr[i+1]);
            swapped = true;
        }
    }
    if (!swapped) {
        return;
    }
    bubbleSort(arr, n - 1);
}
