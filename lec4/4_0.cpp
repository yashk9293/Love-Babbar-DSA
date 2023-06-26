#include <iostream>
using namespace std;

int main() {                                                           // Input :-
    int n;                                                             // 5
    cin>>n;                                                            // Output :-
    for(int i=0;i<n;i++){                                              // 1 2 3 4 5
        for(int j=1;j<=n;j++){                                         // 1 2 3 4 5
            cout<<j<<" ";                                              // 1 2 3 4 5
        }                                                              // 1 2 3 4 5
        cout<<" \n";                                                   // 1 2 3 4 5
    }
    return 0;
}


// int main() {
//     int n;
//     cin>>n;                                                        // Input :-
//     int i=1;                                                       // 3
//     while(i<=n) {
//         int j=1;                                                   // Output :-
//         while(j<=n) {                                              // 1 2 3
//             cout<< j << " ";                                       // 1 2 3
//             j++;                                                   // 1 2 3
//         }
//         cout<<endl;
//         i++
//     }
// }


// int main() {
//     int n;                                                              // Input :-
//     cin>>n;                                                             // 5
//     for(int i=0;i<n;i++){                                               // Output :-
//         for(int j=n; j; j--){                                           // 5 4 3 2 1
//             cout<<j<<" ";                                               // 5 4 3 2 1
//         }                                                               // 5 4 3 2 1
//         cout<<" \n";                                                    // 5 4 3 2 1
//     }                                                                   // 5 4 3 2 1
//     return 0;
// }




// int main() {
//     int n;
//     cin>>n;                                                        // Input :-
//     int i=1;                                                       // 3
//     while(i<=n) {
//         int j=1;                                                   // Output :-
//         while(j<=n) {                                              // 3 2 1
//             cout<< n-j+1 << " ";                                   // 3 2 1
//             j++;                                                   // 3 2 1
//         }
//         cout<<endl;
//         i++
//     }
// }




// int main() {
//     int n;
//     cin>>n;                                                         // Input :-
//     for(int i=0;i<n;i++){                                           // 5
//         for(int j=1;j<=n;j++){                                      // Output :-
//             cout<<j+(n*i)<<" ";                                     // 1 2 3 4 5
//         }                                                           // 6 7 8 9 10
//         cout<<"\n";                                                 // 11 12 13 14 15
//     }                                                               // 16 17 18 19 20
//     return 0;                                                       // 21 22 23 24 25
// }


// int main () {
//     int n;
//     cin>>n;
//     int i=1;
//     int count = 1;                                                 // Input :-
//     while(i<=n) {                                                  // 3
//         int j=1;
//         while(j<=n) {                                              // Output :-
//             cout << count << " ";                                  // 1 2 3
//             count++;                                               // 4 5 6
//             j++;                                                   // 7 8 9
//         }
//         cout<<endl;
//         i++;
//     }
//     return 0;
// }


// ______________________________
// ******************************
// int main () {                                                            // Input :-
//     int n,sum=0;                                                         // 3
//     cin>>n;
//     for (int i = 1; i <= n; i++) {                                       // Output :-
//         for (int j = 1; j <= i; j++) {                                   // 1
//             cout << sum+j << " ";                                        // 2 3
//         }                                                                // 4 5 6
//         cout << " \n";
//         sum=sum+i;
//     }
// }




// int main () {
//     int n;
//     cin>>n;                                                           // Input :-
//     int i = 1;                                                        // 3
//     whiel(i<=n) {
//         int j=1;                                                      // Output :-
//         while(j<=i) {                                                 // *
//             cout<<"*";                                                // **
//             j++;                                                      // ***
//         }
//         cout<<endl;
//         i++;
//     }
// }



// int main () {
//     int n;
//     cin>>n;                                                           // Input :-
//     int i = 1;                                                        // 3
//     whiel(i<=n) {
//         int j=1;                                                      // Output :-
//         while(j<=i) {                                                 // 1
//             cout<<i;                                                  // 22
//             j++;                                                      // 333
//         }
//         cout<<endl;
//         i++;
//     }
// }



// int main () {                                                      // Input :-
//     int n;                                                         // 3
//     cin>>n;                       
//     for (int i = 1; i <= n; i++) {                                 // Output :-
//         for (int j = 1; j <= i; j++) {                             // 1
//             cout << i << " ";                                      // 2 2
//         }                                                          // 3 3 3
//         cout << " \n";
//     }
// }



// int main () {
//     int n;
//     cin>>n;                                                           // Input :-
//     int i = 1;                                                        // 4
//     while(i<=n) {
//         int j=1;                                                      // Output :-
//         int value = i;
//         while(j<=i) {                                                 // 1
//             cout<<value;                                              // 23
//             value++;                                                  // 345
//             j++;                                                      // 4567
//         }
//         cout<<endl;
//         i++;
//     }
// }





// int main () {
//     int n;
//     cin>>n;                                                           // Input :-
//     int i = 1;                                                        // 4
//     while(i<=n) {
//         int j=1;                                                      // Output :-
//         while(j<=i) {                                                 // 1
//             cout<<i+j-1;                                              // 23
//                                                                       // 345
//             j++;                                                      // 4567
//         }
//         cout<<endl;
//         i++;
//     }
// }






// int main () {
//     int n;
//     cin>>n;                                                           // Input :-
//     int i = 1;                                                        // 4
//     whiel(i<=n) {
//         int j=1;                                                      // Output :-
//         while(j<2*i) {                                                // 1
//             cout<<j;                                                  // 123
//             j++;                                                      // 12345
//         }                                                             // 1234567
//         cout<<endl;
//         i++;
//     }
// }






// int main () {
//     int n;
//     cin>>n;                                                           // Input :-
//     int i = 1;                                                        // 4
//     whiel(i<=n) {
//         int j=1;                                                      // Output :-
//         while(j<=i) {                                                 // 1
//             cout<<i-j+1;                                              // 21
//             j++;                                                      // 321
//         }                                                             // 4321
//         cout<<endl;
//         i++;
//     }
// }





// int main()
// {                                                               // Input :-
//     int n;                                                      // 5
//     cin>>n;
//     for(int i=1;i<=n;i++){                                      // Output :-
//         for(int j=1;j<=i;j++){                                  // 1
//             cout<< i-j+1<<" ";                                  // 2 1
//         }                                                       // 3 2 1
//         cout<<" \n";                                            // 4 3 2 1
//     }                                                           // 5 4 3 2 1
// }


