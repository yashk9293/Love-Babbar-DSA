// Prime or Not

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int i = 2;

    while(i<n) {
        if(n%i==0) {
            cout<<"Not prime for " << i << endl;
        }
        else {
            cout<<"Prime for " << i << endl;
        }
        i++;
    }
}


// input :-
// 14

// Output :-
// Not prime for 2
// Prime for 3
// Prime for 4
// Prime for 5
// Prime for 6
// Not prime for 7
// Prime for 8
// Prime for 9
// Prime for 10
// Prime for 11
// Prime for 12
// Prime for 13
