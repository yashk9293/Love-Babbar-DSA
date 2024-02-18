// Question Link :- https://www.codingninjas.com/studio/problems/reverse-the-string_799927
// Reverse the String

void reverse(string& str, int i, int j) {
	if(i>j) {
		return;
	}
	swap(str[i], str[j]);
	i++;
	j--;

	reverse(str, i, j);
}


string reverseString(string str) {
	reverse(str, 0, str.length()-1);
	return str;
}







// Question Link - https://leetcode.com/problems/reverse-string/

// Using Recursion
class Solution {
public:
    void reverse(vector<char> &s, int i, int j) {
        if(i>j) {
            return;
        }
        swap(s[i], s[j]);
        i++;
        j--;
        reverse(s, i, j);
    }
    void reverseString(vector<char>& s) {
        reverse(s, 0, s.size()-1);
    }
};




// Best Approach is using 2 pointer
class Solution {
public:
    void reverseString(vector<char>& s) {
        int end=s.size()-1;
        int start=0;
        while(start<s.size()/2){
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};
