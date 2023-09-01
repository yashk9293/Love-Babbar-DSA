// Default Arguments

#include<iostream>
using namespace std;

// default argument is always passed in function from right to left
void print(int arr[], int n  , int start = 0) {
    for(int i = start; i<n; i++) {
        cout << arr[i] << "";
    }
    cout << endl;
}

int main() {
    int arr[5] = {1,4,7,8,9};
    int size = 5;

    print(arr, size);
    cout << endl;
    print(arr, size, 2);

    return 0;
}

// Output :-

// 14789

// 789




// Constant Variables - if we declare any keyword as constant, we can't change its value throughout the program. The constant 
//                      variable needs to be assigned during initialization only, else it will store garbage values that can't 
//                      be changed further.

// const int a = 5;