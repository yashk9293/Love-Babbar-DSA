// Question Link :- https://www.codingninjas.com/studio/problems/check-palindrome_920555
// Check If Binary Representation of a Number is Palindrome


#include <bits/stdc++.h> 
bool check_palindrome(string &s) {
	int i=0;
	int j=s.size()-1;
	while(i<j) {
		if(s[i]!=s[j])
		    return false;
		else {
			i++;
			j--;
		}
	}
	return true;
}

bool checkPalindrome(long long N) {
    string s="";
	while(N!=0) {
		s.push_back(char(N%2)+'0');
		N/=2;
	}
	reverse(s.begin(),s.end());
    return  check_palindrome(s);
}