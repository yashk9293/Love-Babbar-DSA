// GCD/ HCF
// formula -> gcd(a,b) = gcd(a-b, b) = gcd(a%b, b)

// other formula = lcm(a,b) x gcd(a,b) = a x b

// reference - https://www.codingninjas.com/codestudio/library/gcd-euclidean-algorithm

#include<iostream>
using namespace std;

int gcd(int a, int b) {
    if(a==0) return b;
    if(b==0) return a;

    while(a != b) {
        if(a>b) {
            a = a-b;
        }
        else {
            b = b-a;
        }
    }
    return a;
}

int main() {
    int a,b;
    cout << "Enter the Values of a and b" << endl;
    cin >> a >> b;
    int ans = gcd(a,b);
    cout << " The GCD of " << a << " & " << b << " is: " << ans << endl;
    return 0;
}








// Question Link - https://leetcode.com/problems/find-greatest-common-divisor-of-array

// Method - 1
class Solution {
public:
    int gcd(int a, int b) {
        if(a==0) return b;
        if(b==0) return a;

        return gcd(b, a%b);
    }
    int findGCD(vector<int>& nums) {
        int max= *max_element(nums.begin(),nums.end());
        int min= *min_element(nums.begin(),nums.end());
        return gcd(min, max);
    }
};



// Method - 2
class Solution {
public:
    int gcd(int min, int max) {
        int GCD = 0;
        for (int i = 1; i <= min; ++i) {
            if (min % i == 0 && max % i == 0) {
                GCD = i;
            }
        }
        return GCD;
    }
    int findGCD(vector<int>& nums) {
        int max= *max_element(nums.begin(),nums.end());
        int min= *min_element(nums.begin(),nums.end());
        return gcd(min, max);
    }
};
