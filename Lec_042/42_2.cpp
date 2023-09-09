#include<iostream>
using namespace std;

class Hero{
    private:
    int health;

    public:
    char level;

    Hero() {
        cout << "Constructor called" << endl;
    }

    // Parameterized Constructor
    Hero(int health) {
        // cout << "this -> " << this << endl;       // 0x61ff04
        this -> health = health;
    }

    Hero(int health, char level) {
        this -> level = level;
        this -> health = health;
    }

    void print() {
        cout << level << endl;
    }

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

int main() {
    // statically
    Hero ramesh(21);
    // cout << "address of ramesh : " << &ramesh << endl;    // 0x61ff04
    ramesh.print();

    //dynamically
    Hero *ramu = new Hero(20);
    ramu -> print();

    Hero temp(22, 'B');
    temp.print();

    Hero Krrish;

}



// Output :-

// T  (garbage value)
// └  (garbage value)
// B
// Constructor called