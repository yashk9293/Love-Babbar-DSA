/* Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value 
to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0. */


// digit = 123
// ans = 0
// ans = digit x 10^0 + ans
//     = 1 x 10^0 + ans
//     = 1

// ans = digit x 10^1 + ans
//     = 2 x 10^1 + 1
//     = 21

// ans = digit x 10^2 + ans
//     = 3 x 10^2 + 21
//     = 321   ----------> reverse


//  ___________________________
// |ans = (digit x 10^i) + ans;|  ----> Formula for reversing no. if we are taking digit from starting
// |___________________________|



// digit = 123
// ans = 0
// ans = (ans x 10) + digit
//     = (0 x 10) + 1
//     = 1

// ans = (ans x 10) + digit
//     = (1 x 10) + 2
//     = 12

// ans = (ans x 10) + digit
//     = (12 x 10) + 3
//     = 123

//  ___________________________
// |ans = (ans x 10) + digit;  |  ----> Formula for same no. if we are taking digit from starting
// |___________________________|


//  ___________________________
// |ans = (ans x 10) + digit;  |  ----> Formula for reversing no. if we are taking digit from ending
// |___________________________|



#include <iostream>
#include <limits.h>
using namespace std;

int main() {
    int x;
    cin>>x;
    int ans = 0;
    while (x != 0){
        int digit = x % 10;
        if ((ans > INT_MAX / 10) || (ans < INT_MIN / 10)){
            return 0;
        }
        ans = (ans * 10) + digit;
        x = x / 10;
    }
    cout<< ans;
}

// input :-
// -754
// 869

// Output :-
// -457
// 968
