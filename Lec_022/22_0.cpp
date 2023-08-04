// Question Link :- https://leetcode.com/problems/reverse-string/

#include<string>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    void reverseString(vector<char>& s) {
        int st=0;
        int e = s.size()-1;

        while(st<e) {
            swap(s[st++], s[e--]);
        }
    }
};











// Question Link :- https://bit.ly/3E55FvF 
// Check Palindrome

#include<iostream> 
using namespace std;

int getLength(char name[]) {
    int count = 0;
    for(int i = 0; name[i] != '\0'; i++) {
        count++;
    }

    return count;
}

char toLowerCase(char ch) {
    if(ch >='a' && ch <='z')
        return ch;
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool checkPalindrome(char a[], int n) {
    int s = 0;
    int e = n-1;
    while(s<=e) {
        if(toLowerCase( a[s] ) != toLowerCase( a[e] ) ) {
            return 0;       
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}
int main( ) {
    char name[20];
    cout << "Enter your name " << endl;
    cin >> name;
    int len = getLength(name);
    cout <<" Palindrome or Not: " << checkPalindrome(name, len) << endl;
    return 0;
}













// Question Link :- https://leetcode.com/problems/valid-palindrome/
// Valid Palindrome
#include<string>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
private:
    bool valid(char ch) {
        if( (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            return 1;
        }
        
        return 0;
    }

    // for converting upper case to lower case simply add ( ch+32 ) and for converting lower case 
    // to upper case simply subtract ( ch-32 )
    
    char toLowerCase(char ch) {
        if( (ch >='a' && ch <='z') || (ch >='0' && ch <='9') )
            return ch;
        else{
            char temp = ch - 'A' + 'a';
            return temp;
        }
    }
    bool checkPalindrome(string a) {
        int s = 0;
        int e = a.length()-1;

        while(s<=e) {
            if(a[s] != a[e]) {
                return 0;       
            }
            else{
                s++;
                e--;
            }
        }
        return 1;
    }

public:
    bool isPalindrome(string s) {
        //faltu character hatado
        string temp = "";
        for(int j=0; j<s.length(); j++) {   
            if(valid(s[j])) {
                temp.push_back(s[j]);
            }
        }
        //lowercase me kardo
        for(int j=0; j<temp.length(); j++) { 
            temp[j] = toLowerCase(temp[j]);
        }
        //check palindrome
        return checkPalindrome(temp);
    }
};