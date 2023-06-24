#include <iostream>
using namespace std;

int main()                                                   // Input :-
{                                                            // 5
    int n;
    cin>>n;                                                  // Output :-
    for(int i=0;i<n;i++){                                    // * * * * *
        for(int j=0;j<n;j++){                                // * * * * *
            cout<<"*"<<" ";                                  // * * * * *
        }                                                    // * * * * *
        cout<<" \n";                                         // * * * * *
    }

    return 0;
}



// int main () {
//     int n;
//     cin>>n;
//     int i=1;
//     while(i<=n) {
//         int j=1;
//         while(j<=n) {
//             cout<<"*"<<" ";
//             j++;
//         }
//         cout<<endl;
//         i++;
//     }
// }






