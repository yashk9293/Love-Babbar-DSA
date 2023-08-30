/*
_____________________________________________________________________________________
|Static Memory Allocation                |             Dynamic Memory Allocation    |
|________________________________________|__________________________________________|
|Memory is released automatically        | Memory is released manually.             |
|                                        |       "delete" keyword                   |
|                                        |     int* i = new int;                    |
|                                        |     delete i;                            |
|                                        |                                          |
|                                        |     int* arr = new int[50]               |
|                                        |     delete []arr;                        |
|________________________________________|__________________________________________|

*/


// VOID POINTER :-

#include <iostream>
using namespace std;

int main() {
	int a = 10;
	void* ptr = &a;
	// The void pointer 'ptr' is cast to an integer pointer using '(int*)ptr' Then, the value 
    // is dereferenced with `*(int*)ptr` to get the value at that memory location
	cout << *(int*)ptr << endl;

	return 0;
}

// Output :-
// 10


// Address Typecasting :-
// Link - https://www.codingninjas.com/studio/guided-paths/basics-of-c/content/118785/offering/1381137