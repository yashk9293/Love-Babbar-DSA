// creating a 2d array with dynamic memory allocation using heap
//                               _    ________
// int** arr = new int* [n]  -> |    | int* n | -> |__|__|__|__| -> array
//                              |    | int* n | -> |__|__|__|__| -> array
//                              |    | int* n |
//                         n  __|    |    :   |
//                              |    |    :   |
//                              |    |    .   |
//                              |    | int* n |
//                              |_   |________|



#include <iostream>
using namespace std;

int main() {

    int row;
    cin >> row;

    int col;
    cin >> col;

    //creating a 2D array
    int** arr = new int*[row];
    for(int i=0; i<row; i++) {
        arr[i] = new int[col];
    }

    //taking input
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cin >> arr[i][j];
        }
    }

    //taking output
    cout << endl;
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout << arr[i][j] << " ";
        } cout << endl;
    }


    //releasing memory
    for(int i=0; i<row; i++) {
        delete [] arr[i];
    }   

    delete []arr;

    //how to create a 2D array dynamically
    //input/Output
    //memory free kaise karani hai 

    return 0;
}


// Output :-

// 3
// 5                
// 4 5 8 7 9
// 5 1 2 6 4
// 3 6 4 7 8

// 4 5 8 7 9 
// 5 1 2 6 4 
// 3 6 4 7 8 