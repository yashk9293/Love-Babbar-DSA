#include<iostream>
using namespace std;

class Human {
    private:
    int age;

    public: 
    int height;
    int weight;

    int getAge() {
        return this->age;
    }

    void setWeight(int w) {
        this->weight = w;
    }
};

// public superclass - public access
class Male1: public Human {
    public:
    string color;

    void sleep() {
        cout << "Male Sleeping" << endl;
    }
};

// public superclass - protected access
class Male2: protected Human {
    public:
    string color;

    void sleep() {
        cout << "Male Sleeping" << endl;
    }

    int getHeight() {
        return this->height;
    }
};

// public superclass - private access
class Male3: private Human {
    public:
    string color;

    void sleep() {
        cout << "Male Sleeping" << endl;
    }

    int getHeight() {
        return this->height;
    }
};



int main() {
    Male1 m1;
    cout << m1.height << endl;

    Male2 m2;
    cout << m2.getHeight() << endl;

    Male2 m3;
    cout << m3.getHeight() << endl;

    return 0;
}



// Output :-

// 1983832432 (garbage value)
// 1983807843 (garbage value)
// 1983808063 (garbage value)