// Question Link - https://leetcode.com/problems/reverse-string/
// Reverse String

// Using Recursion
// T.C = O(n)
// S.C = O(n)
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
// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    void reverseString(vector<char>& s) {
        int end=s.size()-1;
        int start=0;
        while(start < s.size()/2){
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};
