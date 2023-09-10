#include<iostream>
using namespace std;

class Human {
    protected:
    int height;

    private:
    int age;

    public: 
    int weight;

    int getAge() {
        return this->age;
    }

    void setWeight(int w) {
        this->weight = w;
    }
};

// protected superclass - public access
class Male1: public Human {
    public:
    string color;

    void sleep() {
        cout << "Male Sleeping" << endl;
    }
};

// protected superclass - protected access
class Male2: protected Human {
    public:
    string color;

    void sleep() {
        cout << "Male Sleeping" << endl;
    }

    int getHeight() {
        return this->height;        // can use protected data member inside class
    }
};

// protected superclass - private access
class Male3: private Human {
    public:
    string color;

    void sleep() {
        cout << "Male Sleeping" << endl;
    }

    int getHeight() {
        return this->height;            // can use protected member inside class
    }
};



int main() {
    Male1 m1;
    cout << m1.height << endl;

    Male2 m2;
    cout << m2.height << endl;

    Male2 m3;
    cout << m3.height << endl;

    return 0;
}