// Question Link :- https://leetcode.com/problems/reorganize-string/
// Reorganize String (codestorywithMIK)

// Approach - 1 (Using max heap)
// T.C = O(N * log(N))
// S.C = O(26) [heap storing k unique elements) + O(N) [result string] = O(N)
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        // Step 1 : storing the characters of s in the frequency vector
        vector<int> freq(26,0);
        for(char &ch : s) {      // O(n)
            freq[ch-'a']++;
            if(freq[ch-'a'] > (n+1)/2) {
                return "";
            }
        }
        // Step 2 : storing the frequency and character in priority_queue
        priority_queue<pair<int, char>> pq;
        for(int i=0; i<26; i++) {     // O(26) ~ O(1)
            char ch = i + 'a';
            if(freq[i] > 0) {
                pq.push({freq[i], ch});
            }
        }
        // Step 3 : Traversing the pq and adding it to result string
        string result = "";
        while(pq.size() >= 2) {   // O(N* log(K))
            auto P1 = pq.top(); 
            pq.pop();
            
            auto P2 = pq.top();
            pq.pop();
            
            result.push_back(P1.second);
            result.push_back(P2.second);
            
            P1.first--;
            P2.first--;
            
            if(P1.first > 0) {
                pq.push(P1);
            }
            if(P2.first > 0) {
                pq.push(P2);
            }
        }
        // If one element is left in the priority_queue
        if(!pq.empty()) {
            result.push_back(pq.top().second);
        }
        return result;
    }
};









// Approach - 2 (Array sort - odd/even placement)
// T.C = O(N + 26log(26)) = O(N)
// S.C = O(26) [freq storing k unique elements) + O(N) [result string] = O(N)
// we can say S.C = O(1) and extra auxiliary space for returning string result = O(N)
class Solution {
public:
    string reorganizeString(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        int maxFreq = 0;
        char maxFreqCh;
        // Step 1 : storing the characters of s in the freq vector, and calculating the maxFreq and maxFreqCh
        for(char &ch : s) {
            freq[ch-'a']++;
            if(freq[ch-'a'] > maxFreq) {
                maxFreq = freq[ch-'a'];
                maxFreqCh = ch;
            }
            if(count[ch-'a'] > (n+1)/2)
                return "";
        }

        string result = s;
        int index = 0;

        // Step 2 : Place the most frequent character in result string
        while (freq[maxFreqCh-'a'] != 0) {
            result[index] = maxFreqCh;
            index += 2;
            freq[maxFreqCh-'a']--;
        }

        // Step 3 : Place rest of the letters in any order
        for (int i=0; i<26; i++) {
            int ch = i + 'a';
            while (freq[ch-'a'] > 0) {
                if (index >= n) {
                    index = 1;
                }
                result[index] = ch;
                index += 2;
                freq[ch-'a']--;
            }
        }
        return result;
    }
};