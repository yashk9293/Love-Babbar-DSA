#include<iostream>
using namespace std;

 long long int sqrtInteger(int n) {
        int s = 0;
        int e = n;
        long long int mid = s + (e-s)/2;
        long long int ans = -1;
        while(s<=e) {
            long long int square = mid*mid;
            if(square == n)
                return mid;
            
            if(square < n ){
                ans = mid; // store the mid in the answer, let n = 17, mid = 4, then square = mid*mid i.e. 16 which is less than 17, so 4 can be stored in the answer. beacause root 17 is 4.something
                s = mid+1;
            }
            else
            {
                e = mid - 1;
            }
            mid = s + (e-s)/2;
        }
        return ans;
    }

double morePrecision(int n, int precision, int tempSol) {
    double factor = 1;
    double ans = tempSol;
    for(int i=0; i<precision; i++) {
        factor = factor/10;
        // 0.1
        // 0.01
        // 0.001
        for(double j=ans; j*j<n; j= j+factor ){
            ans = j;
        }
    }
    return ans;
}

int main() {
    int n;
    cout <<" Enter the number : ";
    cin >> n;

    int tempSol = sqrtInteger(n);
    cout <<" Answer is " << morePrecision(n, 3, tempSol) << endl;

    return 0;
}




// Enter the number : 32
// Answer is 5.656


// Enter the number : 16
// Answer is 4