// (Homework - 1)
// #include <iostream>
// using namespace std;

// int main() {
//   char ch;
//   cout << "Enter a character value: " << endl; 
//   cin >> ch;

//   if (ch >= 'a' && ch <= 'z'){
//     cout << "Entered character is a Lowercase and the value is " << ch << endl; 
//   }
//   else if (ch >='A' && ch <= 'Z'){
//     cout << "Entered character is a Uppercase and the value is " << ch << endl; 
//   }
//   else {
//     cout << "Entered character is a Numeric and the value is " << ch << endl;
//   }
// } 






// Find sum of all even no. from 1-N (Homework - 2)

#include <iostream>
using namespace std;

int main() {
  int n;
  cout << "Enter the value of n : ";
  cin >> n;
  int num = 2;
  int sum = 0;
  while (num <= n){ 
    cout << num <<" ";
    if (num%2 == 0 ){
      sum += num ;
    }
    num += 2;
  }  
  cout << "\nSum of Even numbers from 1 to "<< n << " is : " << sum << endl; 
} 










// Fahrenheit to Celcius (Homework - 3)

// #include <iostream>
// using namespace std;

// int main() {
//     float c,f;
//     cout <<"Enter value of temperature in Fahrenheit : " << endl;
//     cin >> f;
//     c= 5*(f-32)/9;
//     cout << "The value in Celsuis is: "<< c << " degree" << endl;
// }