#include<bits/stdc++.h>
using namespace std;

// arr[i] = i[arr]

int main() {
	int arr[10] = {4, 6 , 9 , 1, 5};
    int i = 3;
	cout << i[arr] << endl;         // 1



	int temp[10] = {1,2};
   	cout << sizeof(temp) << endl;                    // 40
    cout << " 1st " <<  sizeof(*temp) << endl;       // 4
    cout << " 2nd " <<  sizeof(&temp) << endl;       // 8 (address)
    int *ptr = &temp[0];
    cout << sizeof(ptr) << endl ;                    // 8 (address is in hexadecimal and is of 8 byte)
    cout << sizeof(*ptr) << endl ;                   // 4 
    cout << sizeof(&ptr) << endl ;                   // 8 (address)



	int a[20] = {1,2,3,5};
    cout << &a[0] << endl;                  // 0x61fe68
    cout << &a << endl;                     // 0x61fe68
    cout << a << endl;                      // 0x61fe68
    int *p = &a[0];
    cout << p << endl;                      // 0x61fe68
    cout << *p << endl;                     // 1
    cout << &p << endl;	       				// 0x61fe64

	p = p+1;
	cout << p <<endl;                       // 0x61fe6c
}