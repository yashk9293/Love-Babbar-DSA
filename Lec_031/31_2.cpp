// Counting

#include<iostream> 
using namespace std;

void print1(int n) {
    //base case
    if(n == 0) {
        return ;
    }
    //Recursive relation
    print1(n-1);
    cout << n << " ";
}

void print2(int n) {
    //base case
    if(n == 0) {
        return ;
    }
    cout << n << " ";
    //Recursive relation
    print2(n-1);
}

int main() {
    int n;
    cin >> n;
    print1(n);
    cout << endl;
    print2(n);

    return 0;
}



// Output :-

// 9
// 1 2 3 4 5 6 7 8 9
// 9 8 7 6 5 4 3 2 1