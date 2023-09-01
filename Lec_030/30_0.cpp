#include<iostream> 
using namespace std;

int res = 1;  //global variable

#define PI 3.14  // no extra storage or memory is required/created
#define AREA(l, b) (l * b)

// chain macros
#define INSTAGRAM FOLLOWERS
#define FOLLOWERS 138

// Multi line Macro
#define ELE 1, \
            2, \
            3

int main() {
    int r = 5;
    //double pi = 3.14;

    double area = PI * r * r;
    cout << "Area is " << area << endl;

    int l1 = 10, l2 = 5, a;
 
    // Find the area using macros
    a = AREA(l1, l2);
 
    // Print the area
    cout << "Area of rectangle" << " is: "<< a << endl;

    cout << "Geeks for Geeks have " << INSTAGRAM << "K followers on Instagram!" << endl << endl;


    int arr[] = { ELE };
 
    // Print elements
    printf("Elements of Array are:\n");
 
    for (int i = 0; i < 3; i++) {
        cout << arr[i] << ' ';
    }

    return 0;
}


// GFG Article link :- https://www.geeksforgeeks.org/macros-and-its-types-in-c-cpp/



// Output :-

// Area is 78.5
// Area of rectangle is: 50
// Geeks for Geeks have 138K followers on Instagram!

// Elements of Array are:
// 1 2 3