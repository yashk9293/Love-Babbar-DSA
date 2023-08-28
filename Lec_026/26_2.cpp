#include<iostream>
using namespace std;

int main() {

    int arr[5] = {1,2,3,4,5};
    char ch[6] = "abcde";


    cout << arr << endl;               // address of arr[0] is printed i.e., 0x61fef4
    //attention here
    cout << ch << endl;                // abcde
    
    char *c = &ch[0];
    //prints entire string
    cout << c << endl;                 // abcde

    char temp = 'z';
    char *p = &temp;

    cout << p << endl;                 // z☺j


    return 0;
}