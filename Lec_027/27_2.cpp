#include<iostream>
using namespace std;

void Q(int z) {
    z += z;
    cout<< z << " ";                               // 14
}

void P(int *y) {
    int x = *y + 2;
    Q(x);
    *y = x - 1; 
    cout << x << " ";                              // 7
}


int f(int x, int *py, int **ppz) {
    int y, z;
    **ppz += 1;                       // c is now 4 + 1 = 5
    z = **ppz;                        // z = 5
    *py += 2;                         // c is now = 5 + 2 = 7
    y = *py;                          // y = 7
    x += 3;                           // x = 4 + 3 = 7
    return x + y + z;                 // 7 + 7 + 5 = 19
}



int main() {
    int first = 100;
    int *p = &first;
    int **q = &p;
    int second = ++(**q);                          // second will be 101
    int *r = *q;                                   // i.e. *r = &first (address of first)
    ++(*r);                                        // first = 101 + 1 = 102
    cout << first << " " << second << endl;        // 102 101


    int arr[] = {41, 52, 36, 74};
    int *pt = (arr + 1);
    cout << *arr + 8 << endl;                      // 41 + 8 = 49


    int x = 5;
    P(&x);
    cout << x << endl;                             // 6


    char ar[20];
    int i;
    for(i = 0; i < 10; i++) {
        *(ar + i) = 65 + i;
    }
    *(ar + i) = '\0';              // \0 refers to NULL character
    cout << ar << endl;                            // ABCDEFGHIJ


    char *ptr; 
    char str[] = "pqrstuv";
    ptr = str;
    ptr += 3;
    cout << ptr << endl;                           // stuv


    int c, *b, **a;
    c = 4;
    b = &c;
    a = &b;
    cout << f(c, b, a);                            // 19


    float arr_[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    float *ptr1 = &arr_[0];
    cout << ptr1 << " ";                           // 190x61fe98
    float *ptr2 = ptr1 + 3;
    cout << ptr2 << " ";                           // 0x61fea4
    cout << *ptr2 << " ";                          // 90.5
    cout << ptr2 - ptr1 << endl;                   // 3
    cout << endl;


    char st[] = "ABCD";
    for(int i = 0; st[i] != '\0'; i++) {
        cout << st[i]  << " " << *(st)+i << " " << *(i+st) << " " <<  i[st] << " " << endl;
    }
    cout << endl;
    // A 65 A A
    // B 66 B B
    // C 67 C C
    // D 68 D D


    int ***l, **m, *n, ab=8;
    n = &ab;
    (*n)++;                  // ab = 8 + 1 = 9
    m = &n;
    (**m)++;                 // ab = 9 + 1 = 10
    l = &m;
    cout<< *n << " " << **m << " " << ***l;          // 10 10 10
    

    return 0;
}



// Output :-

// 102 101
// 49
// 14 7 6
// ABCDEFGHIJ
// stuv
// 190x61fe80 0x61fe8c 90.5 3

// A 65 A A
// B 66 B B
// C 67 C C
// D 68 D D

// 10 10 10


