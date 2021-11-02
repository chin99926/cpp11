#include <iostream>
#include <algorithm>
#include <utility>
#include <string>

using std::string;


// A global variable
int X = 100;

int & getRef() { return X; }    // Return by ref: getRef() is an lvalue
int getVal() { return X; }      // Return by value: getVal() is an rvalue

void printReference(const string & str) { std::cout << str << std::endl; }
void printReference(string && str) { std::cout << str << std::endl; }


class Data {
    string _name;
    int _size;

public:
    Data(int s, const string & n) : _name(n), _size(s) {}

    Data(const Data & other) : _name(other._name), _size(other._size) {}
    Data(Data && other)
        : _name(std::move(other._name))
        , _size(other._size)
    {
        other._size = 0;
    }

    string getName() const { return _name; }
    int getSize() const { return _size; }
};

class ArrayWrapper {
    int * _array;
    Data _data;

public:
    ArrayWrapper() : _array(new int[64]), _data(64, "default") {}
    ArrayWrapper(int n, const string & s) : _array(new int[n]), _data(n, s) {}

    ArrayWrapper(const ArrayWrapper & other)
        : _array(new int[other._data.getSize()])
        , _data(other._data)
    {
        for (int i = 0; i < _data.getSize(); i++) {
            _array[i] = other._array[i];
        }
    }

    // Move constructor, rvalue needs to be mutable
    // Note: other is an rvalue reference, i.e. lvalue. It then calls
    //       copy constructor in Data. To call move constructor in
    //       Data, use std::move() to cast other
    ArrayWrapper(ArrayWrapper && other)
        : _array(other._array)
        , _data(std::move(other._data)) // Cast lvalue to rvalue
    {
        other._array = NULL;
    }

    void printInfo() {
        std::cout << "_data: name = " << _data.getName()
                  << ", size = " << _data.getSize() << std::endl;
    }

    ~ArrayWrapper() {
        delete [] _array;
    }
};


int main() {

    getRef() = 200;             // OK, lvalue can be assigned
    std::cout << "Assign X with lvalue ref: X = " << X << std::endl;

    const int & x = getVal();   // OK, rvalue can ONLY be assigned to const ref
    // int & x = getVal();      // Not OK

    // Use rvalue reference:
    const int && xx = getVal(); // OK
    int && xxx = getVal();      // OK
    std::cout << "Before assignment: X = " << X << ", xxx = " << xxx << std::endl;
    xxx = 400;
    std::cout << "After assignment: X = " << X << ", xxx = " << xxx << std::endl;

    // lvalue and rvalue functions:
    string name("alex");
    printReference(name);       // Takes lvalue reference
    printReference("alex");     // Takes mutable rvalue reference

    ArrayWrapper arr1(32, "alex");
    arr1.printInfo();

    ArrayWrapper arr2(std::move(arr1));
    std::cout << "--- in arr2 ---" << std::endl;
    arr2.printInfo();
    std::cout << "--- in arr1 ---" << std::endl;
    arr1.printInfo();

    return 0;
}