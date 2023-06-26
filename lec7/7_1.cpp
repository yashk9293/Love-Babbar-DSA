// The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// Given an integer n, return its complement.


#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int m = n;
    int mask = 0;
    if (n == 0){
        return 1;
    }
    while (m != 0){
        mask = (mask << 1) | 1;  // --> in left shifting operator, addition of zero is there at last (i.e. padding) while in right shifting addition of zero is from front.
        m = m >> 1;
    }
    int ans = (~n) & mask; // int ans = n^mask;  
    return ans;
}


// 5 -> 00000101
// ~5 -> 11111010
// mask -> 00000111
// ~5 x mask -> 00000010 == 2



// Input :- 
// 5
// 10

// Output :-
// 2
// 5