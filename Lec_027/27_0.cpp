#include<iostream>
using namespace std;


void update(int **p2) {
    // p2 = p2 + 1;
    //kuch change hoga  - NO

    // *p2 = *p2 + 1;
    //kuch change hoga - YES          // before p : 0x61ff08
                                      // after p : 0x61ff0c

    **p2 = **p2 + 1;
    //kuch change hoga - YES          // before i : 5
                                      // after i : 6
}



void update(int *p){
    *p = (*p)  *  2;
}

void increment(int **p){    // double pointer is passed.
    ++(**p);
}



int main() {
    int i = 5;
    int* p = &i;
    int** p2 = &p;
    cout << "i : " << i << endl;                 // 5
    cout << "*p : " << *p << endl;               // 5
    cout << "**p2 : " << **p2 << endl << endl;   // 5

    cout << "&i : " << &i << endl;               // 0x61ff08
    cout << "p : " << p << endl;                 // 0x61ff08
    cout << "*p2 : " << *p2 << endl << endl;     // 0x61ff08

    cout << "&p : " << &p << endl;               // 0x61ff08
    cout << "p2 : " << p2 << endl << endl;       // 0x61ff08

    cout<< "before i : " << i << endl;
    cout<< "before p : " << p << endl;
    cout<< "before p2 : " << p2 << endl;
    update(p2);
    cout<< "\nafter i : " << i << endl;
    cout<< "after p : " << p << endl;
    cout<< "after p2 : " << p2 << endl << endl;


    int num = 10;
    update(&num);
    cout << num << endl;                         // 20

    int number = 110;
    int *ptr = &number;
    increment(&ptr);              // the address of pointer ptr is passed because double pointer is there in the function increment.
    cout << number << endl;                      // 111

    return 0;
}





// i : 5
// *p : 5
// **p2 : 5

// &i : 0x61ff08
// p : 0x61ff08
// *p2 : 0x61ff08

// &p : 0x61ff04
// p2 : 0x61ff04

// before i : 5
// before p : 0x61ff08
// before p2 : 0x61ff04

// after i : 6
// after p : 0x61ff08
// after p2 : 0x61ff04

// 20
// 111