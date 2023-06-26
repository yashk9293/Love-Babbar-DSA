#include <iostream>
#include <limits.h>
#include<math.h>
#include<string>
using namespace std;

// Method - 1

bool isPowerOfTwo(int n){
    for (int i = 0; i <= 30; i++){
        int ans = pow(2,i);
        if (ans == n){
            return true;
        }
    }
    return false;
}


int main() {
    int n;
    cin>>n;
    cout<<isPowerOfTwo(n);
}
// _______________________________________________________________________________________
// Method - 2


bool isPowerOfTwo(int n){
    int ans = 1;   // initialising ans variable outside for loop so that creation of a varible inside for doestn't happens several times.
    for (int i = 0; i <= 30; i++){
        if(ans == n){
            return true;
        }
        if(ans < INT_MAX/2)
            ans = ans * 2;
    }
    return false;
}


int main() {
    int n;
    cin>>n;
    cout<<isPowerOfTwo(n);
}

// ________________________________________________________________________________________
// Method-3

// 1 = 01
// 2 = 10
// 4 = 100
// 8 = 1000
// 16 = 10000

string DecimalToBinary(int num) {
    string str;
    while (num) {
        if (num & 1) // 1
            str += '1';
        else // 0
            str += '0';
        num >>= 1; // Right Shift by 1
    }
    return str;                  // -> 110111
}

void reverse(string str){
    for (int i = str.size() - 1; i >= 0; i--)
        cout << str[i];          // -> 111011
}

bool isPowerOfTwo(string str){
    int count = 0;
    for(int i=0 ;i< str.length();i++) {
        if(str[i] == '1')
            count++;
    }        
    if(count == 1)
        return true;
    else 
        return false;
}

int main() {
    int num = 59;
    cout << "Binary of num 59 is: ";
    reverse(DecimalToBinary(num));  // 111011
    cout << "\n" << isPowerOfTwo(DecimalToBinary(num));
    return 0;
}


// Input:-
// 16
// 18

// Output :-
// 1
// 0






