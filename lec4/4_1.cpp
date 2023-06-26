#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;                                                    // Input :-
    int i=1;                                                   // 3
    while(i<=n) {
        int j=1;                                               // Output :-
        while(j<=n) {                                          // AAA
            char ch = 'A' + i - 1;                             // BBB
            cout<< ch;                                         // CCC
            j++;
        }
        cout<<endl;
        i++;
    }
}





// int main() {
//     int n;
//     cin>>n; 
//     char ch='A';                                               // Input :-
//     int i=1;                                                   // 3
//     while(i<=n) {
//         int j=1;                                               // Output :-
//         while(j<=n) {                                          // AAA
//             cout<< ch;                                         // BBB
//             j++;                                               // CCC
//         }
//         cout<<endl;
//         i++;
//         ch++;
//     }
// }






// int main () {
//     int n;
//     cin>>n;
//     int i=1;
//     char count = 'A';                                              // Input :-
//     while(i<=n) {                                                  // 3
//         int j=1;
//         while(j<=n) {                                              // Output :-
//             cout << count << " ";                                  // A B C
//             count++;                                               // D E F
//             j++;                                                   // G H I
//         }
//         cout<<endl;
//         i++;
//     }
//     return 0;
// }






// int main () {
//     int n;                                                          // Input :-
//     cin>>n;                                                         // 3
//     char ch='A';
//     for (int i = 1; i <= n; i++) {                                  // Output :-
//         for (int j = 1; j <= i; j++) {                              // A
//             cout << ch << " ";                                      // B C
//             ch=ch+1;                                                // D E F
//         }
//         cout << " \n";
//     }
//     return 0;
// }







// int main() {
//     int n = 4;
//     for (int i = 1; i <= n; i++) {                         // Output :-
//         char count = 'A' + i - 1;                          // A B C D
//         for (int j = 1; j <= n; j++) {                     // B C D E
//             cout << count << " ";                          // C D E F
//             count++;                                       // D E F G
//         }
//         cout << endl;
//     }
//     return 0;
// }






// int main() {
//     int n;
//     cin>>n;                                                    // Input :-
//     int i=1;                                                   // 3
//     while(i<=n) {
//         int j=1;                                               // Output :-
//         while(j<=i) {                                          // A
//             char ch = 'A' + i + j - 1;                         // BC
//             cout<< ch;                                         // CDE
//             j++;
//         }
//         cout<<endl;
//         i++;
//     }
// }







// int main() {
//     int n;
//     cin>>n;                                                    // Input :-
//     int i=1;                                                   // 4
//     while(i<=n) {
//         int j=1; 
//         char start = 'A' + n - i;                              // Output :-
//         while(j<=i) {                                          // D
//             cout<< start;                                      // CD
//             start++;                                           // BCD
//             j++;                                               // ABCD
//         }
//         cout<<endl;
//         i++;
//     }
// }

