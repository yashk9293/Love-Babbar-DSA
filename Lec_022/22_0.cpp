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


// Method - 1
// T.C : O((length(S))
// S.C : O((length(S))

void toLowerCase(string &s) {	
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (ch <= 'Z' && ch >= 'A') {
            ch = ch - ('A' - 'a');
            s[i] = ch;
        }
    }
}

string reverseString(string s) {
    for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
    return s;
}

bool checkPalindrome(string s) {	
    toLowerCase(s);
    string reversedS = reverseString(s);

    int n = s.length();
    int i = 0;
    int j = 0;

    while (i < n && j < n){
        if (isalnum(s[i]) == 0){  // isalnum() is used to check if the input value is either an alphabet or a number
            ++i;
        }
        else if (isalnum(reversedS[j]) == 0){
            ++j;
        }
        else if (s[i] == reversedS[j]){
            ++i; 
            ++j;
        }
        else{
            return false;
        }
    }
    return true;
}




// Method - 2
// T.C : O((length(S))
// S.C : O((1)

void toLowerCase(string &s) {	
    for (int i = 0; i < s.length(); i++){
        char ch = s[i];

        if (ch <= 'Z' && ch >= 'A'){
            ch = ch - ('A' - 'a');
            s[i] = ch;
        }
    }
}

bool checkPalindrome(string s){	
    toLowerCase(s);

    int i = 0;
    int j = s.length() - 1;

    while (i < j){
        if (isalnum(s[i]) == 0){
            ++i;
        }
        else if (isalnum(s[j]) == 0){
            --j;
        }
        else if (s[i] == s[j]){
            ++i, --j;
        }
        else{
            return false;
        }
    }
    return true;
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
