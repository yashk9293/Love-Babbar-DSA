// Question Link :- https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/


#include<string>
#include<iostream>
using namespace std;
string removeDuplicates(string s) {
    string temp = "";
    for (int i = 0; i < s.length(); i++) {
        temp.push_back(s[i]);
        if (temp.size() >= 2 && temp[temp.length() - 1] == temp[temp.length() - 2]) {
            temp.pop_back();
            temp.pop_back();
        }
    }
    return temp;
}



// ------------- Approach - 2 --------------
// string removeDuplicates(string s) {
//     int i = 0;
//     string temp;
//     temp.push_back(s[i]);
//     for (i = 1; i < s.length(); i++) {
//         if (s[i] == temp.back()) {
//             temp.pop_back();
//         }
//         else {
//             temp.push_back(s[i]);
//         }
//     }
//     return temp;
// }






// ------------ Approach - 3 ----------------
// string removeDuplicates(string s) {
//     string res;
//     for(char ch : s){
//         if(!res.empty() && res[res.size() - 1] == ch) 
//             res.pop_back();
//         else res+=ch;
//     }
//     return res;
// }




int main() {
    string s = "abbaca";
    cout<<removeDuplicates(s);
}


// Input: s = "abbaca"
// Output: "ca"
// Explanation: For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and 
// this is the only possible move.  The result of this move is that the string is "aaca", of which only 
// "aa" is possible, so the final string is "ca".



// Input: s = "azxxzy"
// Output: "ay"