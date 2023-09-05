// Reverse the string using recursion
// 1 pointer

#include<iostream>
using namespace std;

// Method - 1

// void reverse(string &str, int n) {
//     static int i = 0;
//     if(i>=n/2) {
//         return;
//     }
//     swap(str[i],str[n-i-1]);
//     i++;
//     reverse(str,n);
// }




// Method - 2

void reverse(string &str,int i=0) {
    if(i==str.size()/2) {
        return;
    }
    swap(str[i],str[str.size()-i-1]);
    reverse(str, ++i);
}


int main() {
    string name = "abcde";
    reverse(name);
    cout << name << endl;

    return 0;
}


// Output :-
// edcba