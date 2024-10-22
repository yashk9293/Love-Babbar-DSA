// Question Link :- https://leetcode.com/problems/count-primes/description/
// Count Primes

// Brute Force
// T.C = O(N*sqrt(N))
// S.C = O(1)
class Solution {
public:
    bool checkPrime(int n) {     // O(sqrt(N))
        int cnt = 0;
        for (int i=2; i*i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int countPrimes(int n) {
        int cnt = 0;
        for(int i=2; i<n; i++) {   // O(N)
            if(checkPrime(i)) {
                cnt++;
            }
        }
        return cnt;
    }
};



// Better Approach
// T.C = O(NlogN)
// S.C = O(N)
class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<bool> prime(n+1, true);

        prime[0]=prime[1] = false;

        for(int i=2; i<n; i++) {   // O(N)
            if(prime[i]) {
                cnt++;
                for(int j=2*i; j<n; j=j+i) {  // O(logN) harmonic series
                    prime[j] = 0;
                }
            }
        }
        return cnt;
    }
};




// Optimised Better Approach
// T.C = O(N*log(logN))
// S.C = O(N)
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n+1, true);
        prime[0] = prime[1] = false;

        for(int i=2; i*i<n; i++) {     // modification 1: for(2 to sqrt(n))
            if(prime[i]) {
                for(int j= i*i; j<n; j+=i) {    // modification 2: start j from i*i
                    prime[j] = 0;
                }
            }
        }
        int cnt = 0;
        // Count primes by checking remaining 1s in the vector.
        for (int i = 2; i < n; i++) {
            if (prime[i] == 1) {
                cnt++;
            }
        }
        return cnt;
    }
};
