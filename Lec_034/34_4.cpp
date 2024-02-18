// Checking Palindrome using recursion 
// 1 pointer

#include<iostream>
using namespace std;

bool checkPalindrome(string &s,int i=0) {
    if(i==s.size()/2) {
        return true;
    }
    if(s[i] != s[s.size()-i-1]) {
        return false;
    }
    return checkPalindrome(s, ++i);
}


int main() {
    string s = "racecar";//7
    cout << boolalpha << checkPalindrome(s);
    // The boolalpha function is a manipulator that sets the boolalpha flag, which tells the  
    // stream to read or write a bool value as text, according to the stream's locale.
}
