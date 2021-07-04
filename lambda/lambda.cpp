#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using std::vector;
using std::string;


int main () {
    // Declare a lambda function
    auto isOdd = [](int candidate) { return candidate % 2 == 1; };

    bool is3Odd = isOdd(3);
    bool is4Odd = isOdd(4);

    vector<int> nums { 2, 3, 4, -1, 1 };

    // Use pre-defined lambda or **locally-defined** lambda
    int odds = std::count_if(nums.begin(), nums.end(), isOdd);
    int evens = std::count_if(nums.begin(), nums.end(),
                              [](int candidate) { return candidate % 2 == 0; });

    // Capture by value and reference explicitly: [x, y, &message]
    int x = 3;
    int y = 7;
    string message = "elements between ";
    message += std::to_string(x) + " and " + std::to_string(y) + " inclusive: ";
    std::for_each(nums.begin(), nums.end(),
                  [x, y, &message](int n) {
                      if (n >= x && n <= y) {
                          message += ' ' + std::to_string(n);
                      }
                  });
    
    std::cout << message << std::endl;
    
    // Capture x by value, others by reference
    x = y = 0;
    std::for_each(nums.begin(), nums.end(),
                  [&, x](int elem) mutable {
                      x += elem;
                      y += elem;
                  });

    std::cout << "x by value: " << x << ", y by ref: " << y << std::endl;

    return 0;
}