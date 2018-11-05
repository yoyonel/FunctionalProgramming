#include <fplus/fplus.hpp>
#include <iostream>

int main()
{
    using namespace fplus;
    const std::string input(
                std::istreambuf_iterator<char>(std::cin.rdbuf()),
                std::istreambuf_iterator<char>());

    const std::string output = to_upper_case(input);

    std::cout << output << std::endl;
}
