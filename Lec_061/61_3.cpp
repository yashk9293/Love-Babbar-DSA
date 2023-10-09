// Question Link :- https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1
// First non-repeating character in a stream

class Solution {
	public:
		string FirstNonRepeating(string A){
		    unordered_map<char, int> count;
		    string ans = "";
		    queue<char> q;
		    
		    for(int i=0; i<A.length(); i++) {
		        char ch = A[i];
		        
		        // increase count
		        count[ch]++;
		        
		        // insert into queue
		        q.push(ch);
		        
		        while(!q.empty()) {
		            // repeating character
		            if(count[q.front()] > 1) {
		                q.pop();
		            }
		            else {
		                // repeating character mil gye
		                ans.push_back(q.front());
		                break;
		            }

		            if(q.empty()) {
		                ans.push_back('#');
		            }
		        }
		    }
		    return ans;
		}
};




// Input :-
// aabc
// Output :-
// a#bb



// Input :-
// aaaabcdebgfhicf
// Ouput:-
// a###bbbbcccccdd



// Input :-
// aaaaeafyredop
// Output :-
// a###eeeeeffff