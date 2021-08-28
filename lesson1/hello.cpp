#include <iostream>
#include <vector>

int sqr (int x);

namespace UnitedKingdom
{
    std::string London{"Big city"};
}

namespace UnitedStates
{
    std::string London{"Small town in Kentucky"};
}

int main (int argc, char *argv[])
{
    for (int i = 1; i < argc; i++) {
        std::cout << argv[i] << std::endl;
    }

    long n_particles{1000};
    const double G{0.987283714758532};
    std::vector<int> u{4,0};    // u = {4, 0}
    std::vector<int> v(4,0);    // v = {0, 0, 0, 0}

#ifdef OLD
    int ii = 2.3;
#else
    // this causes a compilation error
    // int ii{2.3};
    int ii{2};
#endif

    std::cout << "n_particles = " << n_particles << ", G = " << G << std::endl;
    std::cout << "ii = " << ii << std::endl;

    // keyword 'auto' can be used for unambiguous cases
    auto a{45};
    auto f = sqr;
    std::cout << "f = sqr, f(6) = " << f(6) << std::endl;
    // keyword 'decltype' can be used to say "same type as the input"
    decltype(ii) jj{6};

    // use of namespace's
    using namespace UnitedKingdom;
    std::cout << "using namespace UnitedKingdom, London is " << London << std::endl;
    std::cout << "specify namespace UnitedStates, London is "
              << UnitedStates::London << std::endl;

    return 0;
}

int sqr (int x)
{
    return x * x;
}
