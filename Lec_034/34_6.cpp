// a^b = (a^(b/2))^2  ->  if b is even
// a^b = (a^(b/2))^2 X a ->  if b is odd

// 3^10 = (3^5)^2
// 3^11 = (3^5)^2 X 3


#include<iostream>
using namespace std;

int power(int a, int b) {
    if(b==0) {
        return 1;
    }
    if(b==1) {
        return a;
    }
    int ans = power(a, b/2);

    if(b%2==0) {
        return ans * ans;
    }
    else return a * ans * ans;
}

int main() {
    int a, b;
    cin >> a >> b;
    int ans = power(a,b);

    cout << "Answer is " << ans << endl;

    return 0;
}



// Input :-
// 2 10

// Output :-
// Answer is 1024