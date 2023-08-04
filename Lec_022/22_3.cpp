// Question Link :- https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
// Remove All Occurrences of a Substring

#include<string>
#include<iostream>
using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length()!=0 && s.find(part) < s.length()) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};


// Input: s = "daabcbaabcbc", part = "abc"
// Output: "dab"
// Explanation: The following operations are done:
// - s = "daabcbaabcbc", remove "abc" starting at index 2, so s = "dabaabcbc".
// - s = "dabaabcbc", remove "abc" starting at index 4, so s = "dababc".
// - s = "dababc", remove "abc" starting at index 3, so s = "dab".
// Now s has no occurrences of "abc"





// Input: s = "axxxxyyyyb", part = "xy"
// Output: "ab"
// Explanation: The following operations are done:
// - s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
// - s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
// - s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
// - s = "axyb", remove "xy" starting at index 1 so s = "ab".
// Now s has no occurrences of "xy".













// https://leetcode.com/problems/permutation-in-string/
// Permutation in string

class Solution {
    private :
    bool isequal(int arr1[], int arr2[]) {
        for(int i=0; i< 26; i++) {
            if(arr1[i] != arr2[i]) {
                return 0;
            }
        }
        return 1;
    }
public:
    bool checkInclusion(string s1, string s2) {
        int arr1[26] = {0};
        for(int i=0; i< s1.size(); i++) {
            int index = s1[i];
            int count = index - 'a';
            arr1[count]++;
        }

        int windowsize = s1.size();
        int arr2[26] = {0};
        int i =0;
        while(i < windowsize && i<s2.size() ) {
            int index = s2[i];
            int count = index - 'a';
            arr2[count]++;
            i++;
        }


        if(isequal(arr1,arr2)) {
            return 1;
        }

        while(i< s2.size()) {
            int index = s2[i];
            int count = index - 'a';
            arr2[count]++;

            int oldindex = s2[i-windowsize];
            int oldcount = oldindex - 'a';
            arr2[oldcount]--;

            if(isequal(arr1,arr2)) {
                return 1;
            }

            i++;
        }
        return 0;
	}
};





// ----------- Method - 2 ---------------
#include<iostream>
using namespace std;
#include<string.h>
#include<algorithm>
bool checkPer(string s1, string s2){
	while(s1.length()!=0 && s1.find(s2)<s1.length()){
    	if(s1.find(s2) ){
    		return true;
		}
	}
	return false;
}

string rev(string &s2){
    reverse(s2.begin(),s2.end());
    return s2;
}

int main(){
	string s1,s2;
	cout<<"Enter the string ";
	cin>>s1;
	cout<<"\nEnter the permutation: ";
	cin>>s2;
	if(checkPer(s1,s2)){
       rev(s2);  // reversing and checking s2.
	   if(checkPer(s1,s2)){
	    cout<<true;
	        }
	else{
	    cout<<false;
	        }
	}
	rev(s2);   //making s2 as it was.
	return 0;
}