// Reverse the string using recursion
// 2 pointer

#include<iostream>
using namespace std;

void reverse(string& str, int i, int j ) {
    cout << "call recieved for " << str << endl;

    //base case
    if(i>j)
        return ;

    swap(str[i], str[j]);
    i++;
    j--;

    //Recursive call
    reverse(str,i,j);
}

int main() {
    string name = "abcde";
    cout << endl;
    reverse(name, 0 , name.length()-1 );
    cout << endl;
    cout << name << endl;

    return 0;
}


// Output :-

// call recieved for abcde
// call recieved for ebcda
// call recieved for edcba
// call recieved for edcba

// edcba