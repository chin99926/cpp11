#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <iostream>


using std::vector;
using std::string;


void show_vector(string name, vector<int> &v) {
    std::cout << name << ": ";
    std::for_each(v.begin(), v.end(), [](int elem) { std::cout << elem << ' '; });
    std::cout << std::endl;
}


int main () {
    // Populate a vector
    vector<int> v;

    // 1.
    for (int i = 0; i < 5; i++) {
        v.push_back(i);
    }

    // 2. generate_n
    int g{0};
    std::generate_n(std::back_inserter(v), 5, [&]() { return g++; });

    // Sum up elements
    
    // 1.
    int total{0};
    for (auto elem : v) {
        total += elem;
    }

    // 2.
    total = std::accumulate(v.begin(), v.end(), 0);

    // Count occurrence of 3's

    //1.
    int count{0};
    for (auto it = v.begin(); it != v.end(); it++) {
        if (*it == 3) {
            count++;
        }
    }

    // 2.
    count = std::count(v.begin(), v.end(), 3);

    // Remove 2's in vector: do NOT use iterator for erase!

    // 1.
    auto v2 = v;
    for (unsigned int i = 0; i < v2.size(); i++) {
        if (v2[i] == 2) {
            v2.erase(v2.begin() + i);
        }
    }

    // 2.
    auto v3 = v;
    // remove_if moves remaining forward and returns iterator
    // at the new end, use erase to actually remove elements
    auto endv3 = std::remove_if(v3.begin(), v3.end(), [](int elem) { return elem == 2; });
    show_vector("v3", v3);
    v3.erase(endv3, v3.end());
    show_vector("v3", v3);

    return 0;
}