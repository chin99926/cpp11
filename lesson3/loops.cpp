#include <iostream>
#include <string>
#include <list>

int main()
{
    // for loop can be based on ranges in C++ 11
    std::cout << "Following two loops have the same effect: \n"
              << "===== conventional loop =====" << std::endl;
    for (int i = 0; i < 5; i++) std::cout << i << ' ';
    std::cout << "\n===== range-based loop =====" << std::endl;
    for (auto i : {0, 1, 2, 3, 4}) std::cout << i << ' ';

    // This is also valid for other types
    std::cout << "\n===== strings =====" << std::endl;
    for (auto d : {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday"})
        std::cout << d << ' ';

    std::string S{"DUMMYSTRING"};
    std::cout << "\n===== within a string =====" << std::endl;
    for (auto s : S) std::cout << s << ' ';

    std::list<double> L{0.1, 0.3, 0.5, 2.4, 2.8};
    std::cout << "\n===== STL list =====" << std::endl;
    for (auto l : L) std::cout << l << ' ' << std::endl;

    return 0;
}
