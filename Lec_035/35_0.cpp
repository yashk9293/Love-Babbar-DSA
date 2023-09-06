// MERGE SORT (Recusively Implement) - 
// Merge sort is a Recursive Algorithm that continuously splits the array in half until it cannot be further divided i.e., the array has only one element left (an array with one element is always sorted). Then the sorted subarrays are merged into one sorted array.

// it is faster than bubble, selection and insertion sort.


// Article Link - https://www.geeksforgeeks.org/merge-sort/

//             0   1   2   3  4  5   6
//             38  27  43  3  9  82  10

//             0   1   2   3 | 4  5   6
//             38  27  43  3 | 9  82  10
//                 /                \
//                /                  \
//        38  27 | 43  3           9  82 | 10
//          /        \              /       \
//         /          \            /         \
//      38 | 27     43 | 3       9 | 82      10
//      /     \     /     \      /    \       |
//     /       \   /       \    /      \      |
//   38       27  43       3   9       82     10
//    \       /     \     /     \     /       |
//     \     /       \   /       \   /        |
//      27 38         3 43        82 9        10
//        \            /            \        /
//         \          /              \      /
//          3 27 38 43                9 10 82
//               \                      /
//                \                    /
//                  3 9 10 27 38 43 82



#include<iostream>
using namespace std;


// // Merging using copying the elements into 2 new array
void merge(int *arr, int s, int e) {
    int mid = (s+e)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    //copy values
    int mainArrayIndex = s;
    for(int i=0; i<len1; i++) {
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        second[i] = arr[mainArrayIndex++];
    }

    //merge 2 sorted arrays     
    int index1 = 0;
    int index2 = 0;
    mainArrayIndex = s;

    while(index1 < len1 && index2 < len2) {
        if(first[index1] < second[index2]) {
            arr[mainArrayIndex++] = first[index1++];
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }   

    while(index1 < len1) {
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2 ) {
        arr[mainArrayIndex++] = second[index2++];
    }

    delete []first;
    delete []second;
}

void mergeSort(int *arr, int s, int e) {
    //base case
    if(s >= e) {
        return;
    }
    int mid = (s+e)/2;

    //left part sort karna h 
    mergeSort(arr, s, mid);
    
    //right part sort karna h 
    mergeSort(arr, mid+1, e);

    //merge
    merge(arr, s, e);

}

int main() {
    int arr[15] = {3,7,0,1,5,8,3,2,34,66,87,23,12,12,12};
    int n = 15;
    mergeSort(arr, 0, n-1);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    } cout << endl;

    return 0;
}

// Output :-
// 0 1 2 3 3 5 7 8 12 12 12 23 34 66 87 


// T.C - O(N log(N))

// The time complexity of Merge Sort isθ(Nlog(N)) in all 3 cases (worst, average, and best) as merge sort always divides the array into two halves and takes linear time to merge two halves.

// Auxiliary Space: O(N), In merge sort all elements are copied into an auxiliary array. So N auxiliary space is required for merge sort.