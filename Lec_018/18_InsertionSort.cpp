// Question Link :- https://www.naukri.com/code360/problems/insertion-sort_3155179
// Insertion Sort

// T.C = O(n^2)
// S.C = O(1)

// best case - already sorted    -> tc = O(n)
// worst case - reverse sorted

#include <bits/stdc++.h> 
void insertionSort(int n, vector<int> &arr){
    for(int i=0; i<n; i++) {
        int j = i;
        while(j-1 >= 0 && arr[j-1] > arr[j]) {
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
}
