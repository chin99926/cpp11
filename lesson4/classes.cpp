#include <iostream>
#include <memory>
#include <utility>

class Base {
    // In-class initialization
    int b = 0;

public:
    // Compiler-generated implementation for more efficiency
    Base() = default;
    Base(int i) : b(i) {}

    // Delete auto-declared copy constructor and assignment operator
    Base(const Base & b) = delete;
    Base & operator = (const Base & b) = delete;

    virtual void print() {
        std::cout << "Print base class" << std::endl;
    }

    void show() {
        std::cout << "Show base class" << std::endl;
    }

    virtual ~Base() {}
};

class Derived : public Base {
    int d;

public:
    Derived() = default;
    Derived(int i) : d(i) {}

    void print() {
        std::cout << "Print derived class" << std::endl;
    }

    void show() {
        std::cout << "Show derived class" << std::endl;
    }

    ~Derived() = default;
};

int main () {

    std::unique_ptr<Base> bPtr(new Derived());

    // Virtual function, binded at runtime
    bPtr->print();
    // Non-virtual function, binded at compile time
    bPtr->show();

    Base b1{1};
    // Compiler error: assignment operator is deleted
    //Base b2 = b1;

    return 0;
}