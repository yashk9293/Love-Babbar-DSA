// Decimal to Binary Conversion

#include<iostream>
#include<math.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int ans  = 0;
    int i = 0;
    while(n != 0 ) {
        int bit  = n & 1;          // 6 -> 011 or 4 -> 001 then we have to reverse it
        ans = (bit * pow(10, i) ) + ans;
        n = n >> 1;
        i++;
    }
    cout<<" Answer is " << ans << endl;
    return 0;
}

// Input :-
// 10

// Output :-
// Answer is 1010






// #include <iostream>
// using namespace std;
// int main() { 
          
//     int n,digit;
//     cout<<" enter ur decimal number ))"<<endl;
//     cin>>n;
//     while(n!=0){
//         digit= n&1;
//         cout<<digit;
//         n= n>>1;
//     }
//     return 0;
// }