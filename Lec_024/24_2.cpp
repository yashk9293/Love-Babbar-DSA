// (a % m)+(b % m)  % m = a+b  % m
// (a % m)−(b % m)  % m = a−b  % m
// (a % m)⋅(b % m)  % m = a⋅b  % m

// reference - https://codeforces.com/blog/entry/72527



// a^b = (a^(b/2))^2  ->  if b is even
// a^b = (a^(b/2))^2 X a ->  if b is odd

// 2^10 = (2^5)^2
// 2^11 = (2^5)^2 X 2


// Question Link :- https://bit.ly/3peOT9i  
// Fast Exponential


// BRUTE FORCE (a^n) : T.C. = O(n)
// ans = 1;
// for(int i=0; i<n; i++) {
//     ans = ans* a;
// }




// T.C. = O(log n)
#include <bits/stdc++.h>

int modularExponentiation(int x, int n, int m) {
	int res=1;
	while(n>0) {
		if(n&1) {
			res= (1LL * res * (x)%m)%m;
		}
		x =(1LL * (x)%m * (x)%m)%m;
		n=n>>1;
	}
	return res;
}





#include<iostream>
using namespace std;

int fastExpo(int a, int b ) {
    int res = 1;
    while(b > 0) {
        if(b&1) {
            //odd
            res = res*a;
        }
        b = b >> 1;
        a = a * a; 
    }
    return res;
}

int main() {
    int a,b;
    cout << "Enter the Values of a and b" << endl;
    cin >> a >> b;
    cout << "Answer is: " << fastExpo(a,b) << endl;
    return 0;
}






// Factorial of 212 mod m, m = 10^9 + 7

#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	long long M = 10^9 + 7;
	long long fact = 1;
	for(int i=2; i<=n; i++) {
		fact = (fact * i) % M;
	}
	cout<<fact;
}