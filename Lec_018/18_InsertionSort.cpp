// Question Link :- https://www.naukri.com/code360/problems/insertion-sort_3155179
// Insertion Sort

// T.C = O(n^2)
// S.C = O(1)

// best case - already sorted    -> tc = O(n)
// worst case - reverse sorted

// 0   1  2  3  4  5  6
// 10  1  7  4  8  2  11

/*
Round 1 :  1 < 10 -> left side
  i=1      10 -> left place
            1th index -> 10 copy karde
            0th index -> 1 copy karde

Round 2 :  1  10 | 7  4  8  2  11
           7<10 -> left
           7>1 -> right

                      3
Round 3 :  1  7  10 | 4  8  2  11
           4<10 -> left

                         4
Round 4 :  1  4  7  10 | 8  2  11

                            5
Round 5 :  1  4  7  8  10 | 2  11

Round 6 :  1  2  4  7  8  10 | 11

Result ->  1  2  4  7  8  10  11
*/
// n-1 round

#include <bits/stdc++.h> 
void insertionSort(int n, vector<int> &arr){
    for(int i=1; i<n; i++) {
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
