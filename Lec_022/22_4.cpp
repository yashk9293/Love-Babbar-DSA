// https://leetcode.com/problems/permutation-in-string/
// Permutation in string
// https://youtu.be/ndnuB4gBbaM

// Brute Force
// T.C = O(n^2 log n)
// S.C = O(1)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        if(n1 > n2) {
            return false;
        }
        sort(s1.begin(),s1.end());
        for(int i = 0; i<n2-n1+1; i++){
            string str = s2.substr(i,n1);
            sort(str.begin(),str.end());
            if(str == s1){
                return true;
            }
        }
        return false;
    }
};





// Optimal Solution
// T.C = O(n1+n2)
// S.C = O(1)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) {
            return false;
        }
        vector<int>v1(26,0);
        vector<int>v2(26,0);
        for(auto ch: s1) {
            v1[ch-'a']++;
        }
        int i = 0 , j = 0;
        while(j<s2.size()) {
            v2[s2[j]-'a']++;
            if(j-i + 1 == s1.size()){
                if(v1 == v2) {
                    return true;
                }
            }
            if(j-i+1 < s1.size()) {
                j++;
            }
            else {
                v2[s2[i]-'a']--;
                i++;
                j++;
            }
        }
        return false;
    }
};