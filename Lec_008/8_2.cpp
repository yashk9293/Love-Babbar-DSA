//HOW WILL YOU EXIT IF YOU PUT SWITCH CASE INSIDE INFINITE LOOP AND WHEN YOU CAN'T USE SWITCH STATEMENT?

#include <iostream>
#include <stdlib.h>
using namespace std;
int main() {
  // this while condition will always be true if exit( is not put.)
  while (1) {
    cout << "HOW YOU DOIN????" << endl;
    int num = 1;
    switch (num) {
    case 1:
      cout << "I'M FINE" << endl;
      break;
    }
    exit(0);
  }
}

//ANSWER: BY PUTTING EXIT(0) , WE CAN EXIT OUT OF INFINITE LOOP.





// Arithmetic Progression

#include <iostream>
using namespace std;

int AP(int n) {
  int ap=3*n+7;
  return ap;
}

int main() {
  int n;
  cin>>n;
  int ans=AP(n);
  cout<<"Answer is="<<ans<<endl;

  return 0;
} 