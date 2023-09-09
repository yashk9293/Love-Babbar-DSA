// Link :- https://www.codingninjas.com/studio/guided-paths/basics-of-c/content/118817/offering/1381800

#include<iostream>
#include "hero3.cpp"    // we can also include class this way by creating a separate .cpp file in same directory
using namespace std;

class Hero{
    private:
    int health;

    public:
    char level;

    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    }
    
};

class Hero2{
    
};

int main() {
    // creating object statically allocation
    Hero ramesh;
    Hero2 h2;
    Hero3 h3;
    cout << "size : " << sizeof(ramesh) << endl;     // 4
    cout << "size : " << sizeof(h3) << endl;     // 8
    cout << "size : " << sizeof(h2) << endl;     // 1
    // in case of empty class, the object gets 1 byte of memory

    //use setter
    ramesh.setHealth(70);
    ramesh.level = 'A';

    cout << "Ramesh Health is: " << ramesh.getHealth() << endl;  // 70
    cout << "Ramesh Level is: " << ramesh.level << endl;         // A

    //dynamicallly
    Hero *ramu = new Hero;
    ramu->setLevel('B');
    ramu->setHealth(80);
    cout << "\nRamu level is  " << (*ramu).level << endl;        // B
    cout << "Ramu level is  " << ramu->level << endl;          // B

    cout << "\nRamu health is " << (*ramu).getHealth() << endl;  // 80
    cout << "Ramu health is " << ramu->getHealth() << endl;    // 80

    return 0;
}


// Constructor - invoke at the time of object creation
//             - no return type
//             - no input parameter