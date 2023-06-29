#include <iostream>
using namespace std;

int main() {
    char ch = '1';
    int num = 1;
    cout << endl;
    switch( 2*num ) {
        case 2: cout << "First" <<endl;
                cout << " First again " <<endl;
                break;          // --> here if break is not there then if, in switch statement this condition is matched then from this condition till further down the output will be executed.

        case '1': switch(num) {
                    case 1: cout<<" Value of num is "<< num <<endl;
                    break;     // --> this break comes out of switch(num)
                 }
                break;        // --> this break comes out of case '1'

        default: cout << " It is default case" <<endl;        
    }
    cout << endl;
    return 0;
}







// WHY WE CAN'T USE CONTINUE STATEMENT IN CASE OF SWITCH CASE?

// ANS: CONTINUE CAN'T BE USED IN CASE OF SWITCH CASE BECAUSE AS THE CASE CONSTANT MATCHES WITH THE USERS 
// INPUT THE FLOW WILL COME DOWN AND TRY TO EXECUTE BUT BECAUSE OF CONTINUE IT WILL SKIP THAT PART AND 
// ITERATION WILL GO ON AND ON. THAT'S WHY WE USE BREAK , TO STOP  AT THE POINT ONCE WE EXUCUTE OUR PART.






// Calculate nth term of the Fibonaci series

#include<iostream>
using namespace std;

int fibonacci(int n) {
    int a = 0;
    int b = 1;
    for (int i = 2; i < n; i++) {
        int next = a + b;
        a = b;
        b = next;
    } 
    return b;
}

int main(){
    int n;
    cin >> n;   
    cout << "The " << n <<"th term of the series is = "<< fibonacci(n) << endl;
    return 0;
}