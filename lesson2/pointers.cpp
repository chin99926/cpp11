#include <iostream>


int main()
{
    int i{5};
    int *iptr{&i};
    i += 1;
    std::cout << "i += 1, then *iptr = " << *iptr << std::endl;
    (*iptr) = 0;
    std::cout << "(*iptr) = 0, then i = " << i << std::endl;

    int &iref{i};
    // int &ireff{7}; // invalid syntax
    iref = 4;
    std::cout << "iref = 4, then i = " << i << std::endl;

    return 0;
}
