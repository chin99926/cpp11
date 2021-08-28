#include <iostream>
#include <string>


int main()
{
    std::string name, bkpname, name_prompt{"What is your name?"};
    std::cout << name_prompt << std::endl;
    std::getline(std::cin, name);

    if (!name.empty()) {
        // simple assignment with `=`, ...
        bkpname = name;

        // and make `name` to uppercase
        for (int i = 0; i < name.size(); i++) {
            name[i] = toupper(name[i]);
        }
        std::cout << bkpname << " <--> " << name << std::endl;
    }

    // Raw string literals
    std::string msg{R"(The tag "\maketitle" is unexpected here.)"};
    // std::string msg{"The tag \"\\maketitle\" is unexpected here."}; // normal escaping
    std::cout << msg << std::endl;

    // Convert to and from strings
    int i{23};
    double tot{0.};
    std::string strtot{"3.54"};
    std::cout << "integer: " << std::to_string(i) << std::endl;
    tot += std::stod(strtot);
    std::cout << "double: " << tot << std::endl;

    return 0;
}
