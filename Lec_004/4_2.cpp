#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;                                                     // Input :-
    int row = 1;                                                // 4
    while(row <= n) {
        //space print karlo                                     //    *
        int space = n - row;                                    //   **
        while(space) {                                          //  ***
            cout<<" ";                                          // ****
            space = space - 1;
        }

        //stars print karlo
        int col = 1;
        while( col <= row ) {
            cout<<"*";
            col = col + 1;
        }
        cout<<endl;
        row = row + 1;
    }
    return 0;
}







// int main() {
//     int n;
//     int i = 1;
//     cin >> n;                                     // Input :-
//     while (i <= n) {                              // 3
//         int star = n - i + 1;
//         while (star) {                            // Output :-
//             cout << "*";                          // ***
//             star = star - 1;                      // **
//         }                                         // *
//         cout << endl;
//         i += 1;
//     }
//     return 0;
// }

// int main() {
//     int n;
//     int i = 1;
//     cin >> n;                                                   // Input :-
//     while (i <= n) {                                            // 4
//         int space = i - 1;
//         while (space) {                                         // Output :-
//             cout << " ";                                        // ****
//             space = space - 1;                                  //  ***
//         }                                                       //   **
//         int star = n - i + 1;                                   //    *
//         while (star) {
//             cout << "*";
//             star -= 1;
//         }
//         cout << endl;
//         i += 1;
//     }
//     return 0;
// }






// int main() {
//     int n;
//     cin>>n;                                                     // Input :-
//     int row = 1;                                                // 4
//     while(row <= n) {                                           // Output :-
//         //print 1st triangle                                    //    1
//         int space = n - row;                                    //   121
//         while(space) {                                          //  12321
//             cout<<" ";                                          // 1234321
//             space = space - 1;
//         }

//         //print 2nd triangle
//         int col = 1;
//         while( col <= row ) {
//             cout<<col;
//             col = col + 1;
//         }

//         // print 3rd triangle
//         int start = row - 1;
//         while(start) {
//             cout<< start;
//             start= start-1;
//         }

//         cout<<endl;
//         row = row + 1;
//     }
//     return 0;
// }




// Dabbang Patern
// int main() {
//     int height, i, j, k, l;
//     cout << endl;
//     cout << "Enter height of the pattern:- ";
//     cout << endl;
//     cin >> height;
//     cout << endl;                                                       
                                                
//     for (i = 1; i <= height; i++) {                                         // Input :-
//         for (j = 1; j <= (height - i + 1); j++) {                           // 5
//             cout << j << " ";
//         }                                                                   // Output :- 
//         for (k = 1; k <= (i - 1); k++) {                                    // 1 2 3 4 5 5 4 3 2 1
//             cout << "* ";                                                   // 1 2 3 4 * * 4 3 2 1
//         }                                                                   // 1 2 3 * * * * 3 2 1
//         for (k = (i - 1); k >= 1; k--) {                                    // 1 2 * * * * * * 2 1
//             cout << "* ";                                                   // 1 * * * * * * * * 1
//         }
//         for (l = (height - i + 1); l >= 1; l--) {
//             cout << l << " ";
//         }
//         cout << endl;
//     }
// }






// Dabbang Pattern
// int main() {
//     int n;
//     cin >> n;
//     int i = 1;
//     while (i <= n){
//         int start = 1;
//         int j = 1;
//         while (j <= n - i + 1){
//             cout << start;
//             start++;
//             j++;
//         }
//         // for stars
//         int star = i - 1;
//         while (star){
//             cout << "*";
//             star--;
//         }
//         int star2 = i - 1;
//         while (star2){
//             cout << "*";
//             star2--;
//         }
//         int count = n - i + 1;
//         while (count){
//             cout << count;
//             count = count - 1;
//         }
//         cout << endl;
//         i = i + 1;
//     }
// }