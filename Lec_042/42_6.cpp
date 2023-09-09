#include<bits/stdc++.h>
using namespace std;

class Hero{
    private:
    int health;

    public:
    char *name;
    char level;
    static int timeToComplete;      // Static keyword, data member belongs to class -> you can access without making an object

    Hero() {
        cout << "Simple Constructor called" << endl;
        name = new char[100];
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
        char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;

        cout << "Copy constructor called" << endl;
        this->health = temp.health;
        this->level = temp.level;
    }

    void print(){
        cout << endl;
        cout << "[ Name: " << this->name<< " ,";
        cout << "health: " << this->health << " ,";
        cout <<"level: " << this->level << " ]";
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

    void setName(char name[]) {
        strcpy(this-> name, name);
    }



    static int random() {
        return timeToComplete ;
    }
    // static functions - no need to create object
    //                  - no "this" keyword is there
    //                  - these functions can only access static members



    //Destructor
    ~Hero() {   
        cout << "Destructor bhai called" << endl;
    }
    
};

int Hero::timeToComplete = 5;

int main() {
    cout << Hero::timeToComplete << endl;
    cout << Hero::random() << endl;

    Hero a;

    cout << a.timeToComplete << endl;


    Hero b;
    b.timeToComplete = 10 ;
    cout  << a.timeToComplete << endl;
    cout << b.timeToComplete << endl;
}




// 5
// 5
// Simple Constructor called
// 5
// Simple Constructor called
// 10
// 10
// Destructor bhai called
// Destructor bhai called




