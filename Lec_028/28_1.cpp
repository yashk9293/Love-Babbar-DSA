// Stack - static memory allocation
// Heap - dynamic memory allocation

// we can create dynamic memory allocation in heap using new keyword.
// new char;  <- it returns the address, it has no name as like in static memory allocation, int i = 5;
// there in order to access heap memory, pointer is mapped.


//   stack        heap
//     |           |
// char* ch = new char;
//      |         |
//      V         V
//    8 byte     1 byte

// total 9 bytes




// int* i = new int;
//    |         |
//    V         V
//  8 byte     4 byte

// total 12 bytes


// creating 5 block size array in heap memory
// new int[5]

// int *arr = new int[5];
//    |          |
//    V          V
//  8 byte      20 byte (5 x 4)

// total 28 bytes




#include<iostream>
using namespace std;

int getSum(int *arr, int n) {

    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    } 
    return sum;
}

int main() {

    int n;
    cin >> n;
    
    //variable size array
    int* arr = new int[n];

    //taking input n in array
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    int ans = getSum(arr, n);

    cout << "answer is : "<< ans << endl;

    //case 1
    while(true) {
        int i = 5;
    }
    // in this case static memory is cleared everytime when the braces are closed and the process goes 
    // on, so all the time it is occupying only 4 byte. Thus the memory is kept creating and clearing.
    
    //case 2
    while(true) {
        int* ptr = new int;
    }
    // in this case the static memory is cleared each time the while is closed but the dynamic memory (new int)
    // is creating again and again, 8 byte static is cleared each time but the 4 byte dynamic memory
    // is always creating leading to memory full which will ultimately cause the program to crash.

    return 0;
}