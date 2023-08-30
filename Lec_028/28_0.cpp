#include<iostream>
using namespace std;

// BAD Practice & error
// int& func(int a) {
//     int num = a;
//     int& ans = num;
//     return ans;
// }

// BAD Practice & error
// int* fun(int n) {
//     int* ptr = &n;
//     return ptr;
// }

void update2(int& n) {
    n++;
}

void update1(int n) {
    n++;
}

int main() {
    int i = 5;
    int& j = i;           // created a ref variable 
    cout << i << endl;    // 5
    i++;
    cout << i << endl;    // 6
    j++;
    cout << i << endl;    // 7
    cout << j << endl;    // 7

    int n = 5;

    // Pass by Value - creates a copy variable inside the function
    cout << "\nBefore : " << n << endl;
    update1(n);
    cout << "After : " << n << endl;

    // Pass by Reference - use the same memory variable, has different name
    cout << "\nBefore : " << n << endl;
    update2(n);
    cout << "After : " << n << endl;

    return 0;
}


// Output :-

// 5
// 6
// 7
// 7

// Before : 5
// After : 5

// Before : 5
// After : 6