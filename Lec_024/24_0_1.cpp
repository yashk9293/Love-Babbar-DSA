// Segmented Seive - it is used for large range
// tc - O(n log(logn))


// Question in 24_0 could be done through segmented seive
// t.c. would be same but auxiliary space would be less in it.



// l=6, h=10
// 1) Generate all prime number from 0 to floor(root h).
// In above example floor(root h) = 3
// primes = {2,3}

// 2) Creat an array of size (h-l+1), ie., (10-6+1)=5
// isPrime = [T T T T T] (initially all true)

// 3) Mark Multiples of prime[] = {2, 3} in isPrime[]
// isPrime = [ F T F F F]


#include<bits/stdc++.h>
using namespace std;

vector<long long> primes;


void seive(int n) {
    vector<bool> isPrime(n+1, true);
    for(long long i=2; i<=n; i++) {  // <=n
        if(isPrime[i]) {
            primes.push_back(i);
            for(int j=2*i; j<=n; j=j+i) {   // <=n
                isPrime[j] = false;
            }
        }
    }
}

void segSeive(long long l, long long h) {
    int cnt = 0;
    long long sq = sqrt(h);
    seive(sq);
    vector<bool> isPrime(h-l+1, true);
    for(long long p : primes) {
        long long smallest_multiple = (l/p)*p;
        if(smallest_multiple < l) {
            smallest_multiple += p;
        }
        for(long long m = smallest_multiple; m<=h; m+=p) {
            isPrime[m-l]=false;
        }
    }
    for(int i=l; i<h; i++) {
        if(isPrime[i-l] == true) {
            cnt++;
        }
    }
}