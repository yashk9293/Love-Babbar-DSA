// Question Link :- https://leetcode.com/problems/string-compression/   (medium)
// String Compression 
// https://youtu.be/I7drewKcN1Y

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int currChar = 0, count = 0, index = 0;
        int i=0;
        while(i<n) {
            currChar = chars[i];
            count =0;
            while(i<n && chars[i] == currChar) {
                count++;
                i++;
            }
            // assigning work
            chars[index] = currChar;
            index++;
            // add the count
            if(count > 1) {
                string strCount = to_string(count);
                for(auto ch : strCount) {
                    chars[index] = ch;
                    index++;
                }
            }
        }
        return index;
    }
};




// Input: chars = ["a","a","b","b","c","c","c"]
// Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
// Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".



// Input: chars = ["a"]
// Output: Return 1, and the first character of the input array should be: ["a"]
// Explanation: The only group is "a", which remains uncompressed since it's a single character.



// Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
// Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
// Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
