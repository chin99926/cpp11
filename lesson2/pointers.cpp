#include <iostream>
#include <memory>


int main()
{
    int i{5};
    int *iptr{&i};

    i += 1;
    std::cout << "i += 1, then i = " << *iptr << std::endl;
    *iptr = 0;
    std::cout << "*iptr = 0, then i = " << i << std::endl;

    int &iref{i};
    // int &ireff{7}; // invalid syntax
    iref = 4;
    std::cout << "iref = 4, then i = " << i << std::endl;

    // Unique pointers (defined in <memory> header)
    std::unique_ptr<int> u1(new int(5));
    // std::unique_ptr<int> u2 = u1; // Compile error
    std::unique_ptr<int> u3 = std::move(u1); // Transfer ownership, u1 is set to nullptr
    u1.reset(); // Does nothing
    u3.reset(); // Deletes memory

    // Shared pointers (also in <memory> header)
    std::shared_ptr<int> s0(new int(5));
    std::shared_ptr<int[]> s1(new int[5]); // Allocates 5 integers
    std::shared_ptr<int[]> s2 = s1; // Both own the memory
    s1.reset(); // Memory still exists due to s2
    s2.reset(); // Free the memory

    // Weak pointers (also in <memory> header)
    std::shared_ptr<int> p1 = std::make_shared<int>(5);
    std::weak_ptr<int> wp1 {p1};
    // Weak pointers share memory with shared pointers, but have no effect on shared pointers
    // Wp copies become empty after all sp copies have been destroyed

    return 0;
}
