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
    cout << "hi" << endl;

    // statically
    Hero ramesh;

    cout << "hello" << endl;

    //dynamically
    Hero *ramu = new Hero;

    cout << "byee" << endl;
}



// Output :-

// hi
// Constructor called
// hello
// Constructor called
// byee