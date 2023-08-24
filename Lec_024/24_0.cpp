// Question Link :- https://leetcode.com/problems/count-primes/
// tc - O(n log(logn))

// BRUTE FORCE
#include<iostream>
using namespace std;

bool isPrime(int n) {
    if(n<=1)
    return false;
    for(int i=2; i<n; i++) {
        if(n%i==0) {
            return false;
        }
    }
    return true;
}
int main() {
    int n;
    cin >> n;
    if(isPrime(n)) {
        cout << "It is a Prime Number" << endl;
    }
    else{
        cout << " It is not a Prime Number" << endl;
    }
    return 0;
}




// Sieve of Eratosthenes
class Solution {
public:
    int countPrimes(int n) {
        int cnt = 0;
        vector<bool> prime(n+1, true);

        prime[0]=prime[1] = false;

        for(int i=2; i<n; i++) {
            if(prime[i]) {
                cnt++;
            }

            for(int j=2*i; j<n; j=j+i) {
                prime[j] = false;
            }
        }
        return cnt;
    }
};








// using while loop
int countPrimes(int n) {

    if (n == 0)
        return false;

    vector<bool> prime(n, true);
    prime[0] = prime[1] = false;
    int ans = 0;

    for (int i = 2; i < n; i++) {
        if (prime[i]) {
            ans++;
            int j = 2 * i;
            while (j < n) {
                prime[j] = false;
                j += i;
            }
        }
    }
    return ans;
};









// same logic other way writing code
#include<iostream>
#include<vector>
using namespace std;

//using Sieve
void sieve(bool prime[]) {

    //setting TRUE for every number
    for(int i=2;i<=1000000;i++) {
        prime[i]=1;
    }
    for(int i = 2; i<=1000000; i++) {
        if(prime[i]){
            //iske saare multiple mark krde - non prime
            for(int j = 2*i; j<=1000000; j+=i){
                prime[j] = 0;   
            }
        }
    }
    prime[0] = prime[1] = 0;
}

int main() {
    bool prime[1000001];
    sieve(prime);

    int n;
    cin >> n;
    while(n!=-1) {
        if(prime[n]) {
            cout << "It is a Prime Number" << endl;
        }
        else {
            cout << " It is not a Prime Number" << endl;
        }
        cin >> n;
    }
    return 0;
}




// Input: n = 10
// Output: 4
// Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.