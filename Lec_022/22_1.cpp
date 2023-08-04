// Question Link :- https://leetcode.com/problems/reverse-words-in-a-string-ii/
// 

#include <iostream>
#include <string.h>
using namespace std;
int main() {
    string s = "my name is yash";
    int start = 0;
    for (int i = 0; i <= s.length(); i++) {
        if (s[i] == ' ' || s[i] == '\0') {
            int end = i - 1;
            while (start <= end) {
                swap(s[start],s[end]);
                start++;
                end--;
            }
            start=i+1;
        }
    }
    cout<<s;
}

// Output :-
// ym eman si hsay









// https://practice.geeksforgeeks.org/problems/maximum-occuring-character-1587115620/1
// Maximum occurence of a character in a string

#include<iostream> 
using namespace std;

char getMaxOccCharacter(string s) {
    int arr[26] = {0};

    //create an array of count of characters
    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        //lowercase
        int number = 0;
        if(ch<='a' && ch<='z') {
            number = ch - 'a';
        }
        else { //Uppercase
            number = ch - 'A';
        }
        arr[number]++;
    }

    //find maximum occ character
    int maxi = -1, ans = 0;
    for(int i=0; i<26; i++) {
        if(maxi < arr[i]) {
            ans = i;
            maxi = arr[i];
        }
    }
    return 'a'+ans;
}

int main( ) {
    string s;
    cin >> s;
    cout << getMaxOccCharacter(s) << endl;
    return 0;
}