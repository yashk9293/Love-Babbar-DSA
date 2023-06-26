#include<iostream>
using namespace std;

// XOR Gate
//  _____________                   XOR ->  a^b = ab' + a'b
// | a | b | a^b |
// |___|___|_____|
// | 0 | 0 |  0  |
// | 0 | 1 |  1  |
// | 1 | 0 |  1  |
// | 1 | 1 |  0  |
// |___|___|_____| 

int main() {

    int a = 4;                                           // 4 = 1 0 0
    int b = 6;                                           // 6 = 1 1 0
    cout<<" a&b " << (a&b) << endl;                      //  -> 1 0 0 = 4 
    cout<<" a|b " << (a|b) << endl;                      //  -> 1 1 0 = 6
    cout<<" ~a " << ~a << endl;                            
    cout<<" a^b " << (a^b) << endl;                      //  -> 0 1 0 = 2

    cout<< (3<<1) <<endl;             // 3 x 2 = 6
    // 3 = 0000000011
    // 3<<1 = 0000000110
    cout<< (3<<2) <<endl;             // 3 x 2 x 2 = 12
    // 3 = 0000000011
    // 3<<2 = 0000001100
    cout<< (17>>1) <<endl;
    cout<< (17>>2) <<endl;

    cout<< (5>>2) <<endl;             // 5 / 2 = 2
    // 5 = 00000000101
    // 5>>1 = 0000000010
    cout<< (5>>2) <<endl;             // 5 / (2 * 2) = 1
    // 5 = 00000000101
    // 5>>2 = 0000000001
    cout<< (19<<1) <<endl;
    cout<< (21<<2) <<endl;

    int i = 7;

    cout<< (++i) <<endl;
    // 8 
    cout<< (i++) <<endl;
    // 8 , i = 9
    cout<< (i--) <<endl;
    //9 , i = 8 
    cout<< (--i) <<endl; 
    // 7, i =7
    return 0;
}


// Fibonacci series - M1
// int main() {
//     int n = 10;
//     int a = 0;
//     int b = 1;
//     cout<<a <<" " <<b<<" ";
//     for(int i = 1; i<=n; i++ ) {
//         int nextNumber = a+b;
//         cout<<nextNumber<<" ";
//         a = b;
//         b = nextNumber;
//     }
//     return 0;
// }



// Fibonacci series - M2
// int main() {
//     //cout<<a;
//     int a=10;
//     cout<<"0 1 ";
//     for(int i=2;i<=a;i++){
//         cout<<(i-1)+(i-2)<<" ";
//     } 
//     return 0;
// }





// Prime no.
// int main() {
//     int n ;
//     cout<<" enter the value of n" <<endl;
//     cin >> n;
//     bool isPrime = 1 ;
//     for(int i = 2; i<n; i++) {
//         //rem = 0, Not a Prime
//         if(n%i == 0) {
//             //cout<<" Not a Prime Number" << endl;
//             isPrime = 0;
//             break;
//         }
//     }
//     if(isPrime == 0) {
//         cout<<" Not a Prime Number"<<endl;
//     }
//     else {
//         cout<<"is a Prime Number "<<endl;
//     }
//     return 0;
// }





// int main() {                                              // Output :-
//     for(int i=0; i<3; i++) {                              // HI
//         cout<< " HI " << endl;                            // Hey
//         cout<< " Hey " << endl;                           // HI
//         continue;                                         // Hey
//         cout<< "Reply toh karde " <<endl;                 // HI
//     }                                                     // Hey
//     return 0;
// }

