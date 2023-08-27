#include<bits/stdc++.h>
using namespace std;

int main() {
	int x=4;
	int *p_x = &x;
    // or
    // int *p_x = 0;     // when initialising a pointer p_x as 0
    // p_x = &x;         // then you should write p_x = &variable

    // copying a pointer
    int *q = p_x;

    char ch='a';
    char *p = &ch; // pointer should have same data type as of the address container

	cout <<"Address of x : "<< &x << endl;               // --> Address of x : 0x61ff08
	cout <<"value of p_x : "<< p_x << endl;              // --> value of p_x : 0x61ff08
	cout <<"Value at  *p_x : "<< *p_x << endl;           // --> Value at  *p_x : 4
	*p_x = 5;
	cout <<"x : "<< x << endl;                           // --> x : 5
	cout << "p_x + 1 : " << p_x + 1 <<endl;              // --> p_x + 1 : 0x61ff0c
	int **p_p_x = &p_x;
	cout << "Address of p_x : " << &p_x <<endl;          // --> Address of p_x : 0x61ff04
	cout <<"Value of p_p_x : "<< p_p_x << endl;          // --> Value of p_p_x : 0x61ff04
	cout <<"Value at  *p_p_x : "<< *p_p_x << endl;       // --> Value at  *p_p_x : 0x61ff08
	cout <<"Value at  **p_p_x : "<< **p_p_x << endl;     // --> Value at  **p_p_x : 5
	**p_p_x=7;
	cout <<"x : "<< x << endl;                           // --> x : 7
}