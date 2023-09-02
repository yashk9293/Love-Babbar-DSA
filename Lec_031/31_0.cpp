// Factorial

#include<iostream> 
using namespace std;

int factorial(int n) {
    
    //base case
    if(n==0)
        return 1;
 
    int res = n * factorial(n-1);

    return res;
}

int main() {
    int n;
    cin >> n;
    int ans = factorial(n);
    cout << ans << endl;

    return 0;
}


// Output :-

// 6
// 720