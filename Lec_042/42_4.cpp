#include<bits/stdc++.h>
using namespace std;

class Hero{
    private:
    int health;

    public:
    char *name;
    char level;

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
    
};

int main() {
    Hero hero1;

    hero1.setHealth(12);
    hero1.setLevel('D');
    char name[5]="yash";
    hero1.setName(name);

    hero1.print();


    Hero hero2(hero1);     // Copy constructor uses shallow copy
    hero2.print();

    hero1.name[0]='k';
    hero1.print();

    hero2.print();
    cout<<endl;

    hero1 = hero2;    // properties of hero2 are copied in hero1

    hero1.print();

    hero2.print();

}



// Simple Constructor called

// [ Name: yash ,health: 12 ,level: D ]
// Copy constructor called

// [ Name: yash ,health: 12 ,level: D ]

// [ Name: kash ,health: 12 ,level: D ]

// [ Name: yash ,health: 12 ,level: D ]


// [ Name: yash ,health: 12 ,level: D ]

// [ Name: yash ,health: 12 ,level: D ]