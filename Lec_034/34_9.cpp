// INSERTION SORT using Recursion (hard)


// space complexity - O(1)
// time complexity - O(n^2)

// best case - already sorted    -> tc = O(n)
// worst case - reverse sorted

// 0   1  2  3  4  5  6
// 10  1  7  4  8  2  11

/*
Round 1 :  1 < 10 -> left side
  i=1      10 -> left place
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


#include <iostream>
using namespace std;

void insertionSort(int* arr, int n, int i) {
    if(i==n || n==0) {
        return;
    }
    int x = arr[i];
    int ind = i;
    for(int j = i-1; j>=0; j--) {
        if(arr[j]>x) {
          ind = j;
        }
    }
    for(int j = i; j>ind; j--) {
        arr[j] = arr[j-1];
    }
    arr[ind] = x;
    insertionSort(arr, n, ++i);
}

int main() {
    int n;
    cin>>n;
    int* arr = new int[n];
    for(int i= 0;i<n;i++) {
        cin>>arr[i];
    }
    cout << "Before sorting" << endl;
    for(int i= 0; i<n;i++) {
        cout<<arr[i]<<" ";
    }
    
    insertionSort(arr, n, 1);
    
    cout << endl << "After sorting" << endl;
    for(int i= 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    delete [] arr;
    return 0;
}



// Input :-

// 5
// 7 4 5 8 1



// Output :-

// Before sorting
// 7 4 5 8 1 
// After sorting
// 1 4 5 7 8 