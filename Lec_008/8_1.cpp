// Calculator

#include<iostream>
using namespace std;

int main() {
    int a, b;
    cout <<" Enter the value of a "<<endl;
    cin >> a;
    cout<<" Enter the value of b " <<endl;
    cin >> b;
    char op;
    cout<<" Enter the Operation you want to perform" <<endl;
    cin >> op;
    switch( op ) {
        case '+':  cout << (a+b) <<endl; 
                  break;

        case '-': cout<< (a-b) <<endl;
                  break;  

        case '*': cout<< (a*b) <<endl;
                  break;

        case '/': cout<< (a/b) <<endl;
                  break;

        case '%': cout<< (a%b) <<endl;
                  break;

        default: cout << "Please enter a valid Operation " << endl;
    }
    return 0;
}




// a^b using function

#include<iostream>
using namespace std;

int power(int num1, int num2) {
    //cout << a <<endl;
    int ans = 1;
    for(int i = 1; i <= num2; i++) {
        ans = ans * num1;
    }
    return ans;
}

int main() {
    int c , d;
    cin>> c >> d;
    int answer = power(c,d);
    cout << " answer is " << answer << endl;
    return 0;
}



// Even/Odd

#include<iostream>
using namespace std;


//1 -> Even
// 0 -> odd
bool isEven(int a) {
    //odd
    if(a&1) {
        return 0;
    }
    else { //Even
        return 1;
    }
}

int main() {
    int num;
    cin >> num;
    if(isEven(num)) {
        cout <<" Number is Even" <<endl;
    }
    else {
        cout<< " Number is Odd" <<endl;
    }
    return 0;
}


// nCr

#include<iostream>
using namespace std;

int factorial(int n) {
    int fact = 1;
    for(int i = 1; i<=n; i++ ) {
        fact = fact * i;
    }
    return fact;
}

int nCr(int n, int r) {
    int num = factorial(n);
    int denom = factorial(r) * factorial(n-r);
    return num/denom;
}

int main( ) {
    int n, r;
    cin>> n >> r ;
    cout <<" Answer is " << nCr(n,r) << endl;
    return 0;
}



// Prime No. or not

#include<iostream>
using namespace std;
// 0 -> Not a Prime no.
// 1 -> Prime no.

bool isPrime(int n ) {
   for(int i = 2; i < n; i++){
       if(n % i == 0) {
       //divide hogya h , not a prime no.
          return 0;
        }
   }
   return 1;
}

int main() {
   int n ;
   cin >> n;
   if(isPrime(n)) {
        cout <<" is a Prime number " <<endl;
   }
   else{
       cout<< "Not a prime number "<<endl;
   }
}



