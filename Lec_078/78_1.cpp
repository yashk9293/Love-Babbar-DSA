// Question Link :- https://www.codingninjas.com/studio/problems/maximum-frequency-number_920319
// Maximum Frequency Number

// T.C = O(n)
// S.C = O(n)
int maximumFrequency(vector<int> &arr, int n) {
    unordered_map<int, int> m;

    int maxFreq = INT_MIN;

    for(int i=0; i<n; i++) {
        m[arr[i]]++;
        maxFreq = max(maxFreq, m[arr[i]]);
    }

    for(int i=0; i<n; i++) {
        if(m[arr[i]] == maxFreq) {
            return arr[i];
        }
    }
}