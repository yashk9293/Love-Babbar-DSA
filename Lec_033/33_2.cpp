// Find whether given no. is present in array or not using linear search in recursion.

#include<iostream>
using namespace std;

// Recursion from forward
void print(int arr[], int n) {
    cout << "Size of array is : " << n << endl;
    cout << "Array : ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    } cout << endl;

}

bool linearSearch(int arr[], int size, int k ) {
    print(arr,size);
    //base case
    if(size == 0) {
        return false;
    }
    if(arr[0] == k) {
        return true;
    } else {
        bool remainingPart = linearSearch(arr+1, size-1, k );
        return remainingPart;
    }
}

int main() {
    int arr[5] = {3,5,1,2,6};
    int size = 5;
    int key = 2;
    bool ans = linearSearch(arr, size, key);
    if(ans ){
        cout << "Present " << endl;
    }
    else{
        cout << "absent " << endl;
    }

    return 0;
}


// Output :-

// Size of array is : 5
// Array : 3 5 1 2 6
// Size of array is : 4
// Array : 5 1 2 6
// Size of array is : 3
// Array : 1 2 6
// Size of array is : 2
// Array : 2 6 
// Present













// Recursion from backward
void print(int arr[], int n) {
    cout << "Size of array is : " << n << endl;
    cout << "Array : ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    } cout << endl;

}

bool linearSearch(int arr[], int size, int k ) {
    print(arr,size);
    //base case
    if(size == 0) {
        return false;
    }
    if(arr[size-1] == k) {
        return true;
    } else {
        bool remainingPart = linearSearch(arr, size-1, k );
        return remainingPart;
    }
}

int main() {
    int arr[5] = {3,5,1,2,6};
    int size = 5;
    int key = 2;
    bool ans = linearSearch(arr, size, key);
    if(ans ){
        cout << "Present " << endl;
    }
    else{
        cout << "absent " << endl;
    }

    return 0;
}



// Size of array is : 5
// Array : 3 5 1 2 6 
// Size of array is : 4
// Array : 3 5 1 2 
// Present 
