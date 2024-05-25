// Is array sorted or not using recursion

#include<iostream>
using namespace std;

bool isSorted(int arr[], int n) {
    //base case
    if(n == 0 || n == 1 ){
        return true;
    }
    return arr[n - 1] >= arr[n - 2] && isSorted(arr, n - 1);
}

int main() {
    int arr[5] = {2,4,9,9,9};
    int size = 5;
    bool ans = isSorted(arr, size);
    if(ans){
        cout << "Array is sorted " << endl;
    } else {
        cout << "Array is not sorted " << endl;
    }

    return 0;
}


// Output :- 
// Array is sorted
