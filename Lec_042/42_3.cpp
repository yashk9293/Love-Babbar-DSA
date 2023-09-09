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

    //copy constructor
    Hero(Hero& temp) {
        cout << "Copy constructor called" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    void print(){
        cout << "health: " << this->health << endl;
        cout <<"level: " << this->level << endl;
        cout << endl;
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
    Hero S(70, 'C');
    S.print();

    // Copy Constructor
    Hero R(S);
    R.print();

}


// health: 70
// level: C

// Copy constructor called
// health: 70
// level: C