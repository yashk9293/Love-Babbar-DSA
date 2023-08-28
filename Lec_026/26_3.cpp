#include<iostream>
using namespace std;

void print(int *p) {
    cout << *p << endl;                                   // 5
}

void update(int *p) {
   *p = *p + 1;
   p = p + 1;
   cout << "inside address : "<< p <<endl;                // 0x61ff0c
}


int getSum(int *arr, int n) {     // or int getSum(int arr[], int n)
    cout << endl << "Size : " << sizeof(arr) << endl; 
    int sum = 0;
    for(int i=0;i<n;i++) {
        sum += arr[i];
    }
    return sum;
}


int main() {
    int value = 5;
    int *p = &value;
    print(p);
    cout <<"Before value : " << *p << endl;               // 5
    cout << "After address : " << p << endl;              // 0x61ff08
    update(p);
    cout << "After address : " << p << endl;              // 0x61ff08
    cout <<"After value : " << *p << endl;                // 6
    // Value is updated in update function but address is not updated.

    int arr[6] = {1, 2, 3, 4, 5, 8};
    cout << "Sum is " << getSum(arr+3, 3) << endl;

    return 0;
}


// Output :-
// 5
// Before value : 5
// After address : 0x61ff08
// inside address : 0x61ff0c
// After address : 0x61ff08
// After value : 6

// Size : 4
// Sum is 17