#include <iostream>
using namespace std;

// Abstract Class
class Animal {
protected:
    string name;

public:
    Animal(string name) {
        this->name = name;
    }

    // Abstract Method (pure virtual)
    virtual void makeSound() = 0;
};

// Derived Class: Dog
class Dog : public Animal {
public:
    Dog(string name) : Animal(name) {}

    void makeSound() override {
        cout << "The dog " << name << " says : Woof!" << endl;
    }
};

// Derived Class: Cat
class Cat : public Animal {
public:
    Cat(string name) : Animal(name) {}

    void makeSound() override {
        cout << "The cat " << name << " says : Meow!" << endl;
    }
};