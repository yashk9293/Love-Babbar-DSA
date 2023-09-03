#include<iostream> 
using namespace std;

void reachHome(int src, int dest) {
    cout << "source " << src  << " destination " << dest << endl;
    //base case
    if(src == dest) {
        cout << "pahuch gya " << endl;
        return ;
    }
    //processing - ek step aage badhjao
    src++;

    //recursive call
    reachHome(src, dest);
}

int main() {
    int dest = 10;
    int src = 1;
    cout << endl;
    reachHome(src, dest);

    return 0;
}

// Output :-

// source 1 destination 10
// source 3 destination 10
// source 4 destination 10
// source 5 destination 10
// source 6 destination 10
// source 7 destination 10
// source 8 destination 10
// source 9 destination 10
// source 10 destination 10
// pahuch gya