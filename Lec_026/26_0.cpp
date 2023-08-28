#include<bits/stdc++.h>
using namespace std;

int main() {
	int a[10];
	a[0] = 2;
	a[1] = 4;
	cout << "a : " << a << endl;
	cout << "&a[0] : " << &a[0] << endl;
	cout << "*a : " << *a << endl;
	cout << "a+1 : " << a + 1 << endl;
	cout << "&a[1] : " << &a[1] << endl;
	cout << "*(a+1) : " << *(a + 1) << endl;
    cout << "*(a) + 1 : " << *(a) + 1 << endl;
}

// Output :-
// a : 0x61fee8
// &a[0] : 0x61fee8
// *a : 2
// a+1 : 0x61feec
// &a[1] : 0x61feec
// *(a+1) : 4
// *(a) + 1 : 3