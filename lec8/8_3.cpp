#include<iostream>
using namespace std;

int main() {
  int amount;
  cout<<"Enter the amount"<<endl;
  cin>>amount;
  int Rs100 , Rs50 , Rs20 , Rs1;

  switch(1)
  {
      case 1: Rs100=amount/100;
              amount=amount%100;
              cout<<"No of 100 Rupee notes required are = "<<Rs100<<endl;
              
         
      case 2: Rs50=amount/50;
              amount=amount%50;
              cout<<"No of 50 Rupee notes required are = "<<Rs50<<endl;
              

      case 3: Rs20=amount/20;
              amount=amount%20;
              cout<<"No of 20 Rupee notes required are = "<<Rs20<<endl;
               

      case 4: Rs1=amount/1;
              amount=amount%1;
              cout<<"No of 1 Rupee notes required are = "<<Rs1<<endl; 
                  
           }
           return 0;
}





// Calculate (setbit of A + setbit of B)

#include <iostream>
using namespace std;

int setBits(int k) {
  int count = 0;
  while(k!=0) {
    if(k&1) {
      count++;
    }
    k=k>>1;
  }
  return count; 
}

int main() {
  int a,b;
  cin>>a>>b;
  int ans1=setBits(a);
  int ans2=setBits(b);
  cout<<"Set bits of A="<<ans1<<endl;
  cout<<"Set bits of B="<<ans2<<endl;
  int ans=ans1+ans2;
  cout<<"Total set bits of A and B are ="<<ans<<endl;

  return 0;
}