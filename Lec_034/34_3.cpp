// Checking Palindrome using recursion 
// 2 pointer

#include<iostream>
using namespace std;


bool checkPalindrome(string str, int i, int  j) {
    //base case
    if(i>j)  {
        return true;
    }
    if(str[i] != str[j]) {
        return false;
    } else{
        return checkPalindrome(str, i+1, j-1);
    }
}

int main() {
    string name = "BookkooB";
    cout << endl;
    bool isPalindrome = checkPalindrome(name, 0, name.length()-1 );

    if(isPalindrome) {
        cout << "Its a Palindrome " << endl; 
    } else {
        cout << "Its not a Palindrome " << endl;
    }

    return 0;
}


// Output :-
// Its a Palindrome
