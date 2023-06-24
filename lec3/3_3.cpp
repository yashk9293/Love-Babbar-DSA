#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int i=1;
    while(i<=n) {
        int j=1;
        while(j<=n) {
            cout<<i;
            j=j++;
        }
        cout<<endl;
        i++;
    }
}

// int main()
// {
//     int n;
//     cin>>n;
//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             cout<<i+1<<" ";
//         }
//         cout<<" \n";
//     }
//     return 0;
// }



// Input :-
// 4

// Output :-
// 1111
// 2222
// 3333
// 4444