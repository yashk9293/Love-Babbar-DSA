#include<iostream>
using namespace std;

int main() {
    int arr[6] = {11, 21, 31};
    int *p = arr;
    // p[2] = *(p+2)
    cout << p[2] << endl;                    // 31

    // int *ptr = arr++;                     // error because we can't do arr = arr +1;
                                             // we can do ptr = ptr +1;

    char ar[] ="abcde";
    char *pt = &ar[0];                       // there is difference in char pointer and int pointer, so it output whole array
    cout << pt << endl;                      // abcde
    cout << ar[0] << " " << pt[0] << endl;   // a a
    pt++;
    cout << pt << endl;                      // bcde
    cout << ar[0] << " " << pt[0] << endl;   // a b

    int first = 110;
    int *ptr = &first;
    int **q = &ptr;
    int second = (**q)++ + 9;                // second will be 110 + 9, as (**q)++ is post increment
    cout << first << " " << second << endl;  // 111 119

    return 0;
}