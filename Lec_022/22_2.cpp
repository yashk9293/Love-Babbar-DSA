// Question Link :- https://bit.ly/3sfP71Q 
// Remove Spaces

#include<string>
#include<iostream>
using namespace std;
string replaceSpaces(string &str){
	string temp = "";
    for(int i=0; i<str.length(); i++) {                   // space complexity - O(n)
        if(str[i] == ' ') {
            temp.push_back('@');
            temp.push_back('4');
            temp.push_back('0');
        }
        else {
            temp.push_back(str[i]);
        }
    }
    return temp;
}









// --------- Method - 2 -------------
string replaceSpaces(string &str){
	// Write your code here.
    int l = str.length();
    string rep = "@40";
    for(int i = 0; i<l ; i++)
    {
        if(str[i]==' ')
        {
            str.replace(i,1,rep);

            // or
            // s.erase(i,1);
            // s.insert(i,str);

        }
    }
    return str;
}





// Input:-
// 2
// Coding Ninjas Is A Coding Platform
// Hello World

// Output :-
// Coding@40Ninjas@40Is@40A@40Coding@40Platform
// Hello@40World