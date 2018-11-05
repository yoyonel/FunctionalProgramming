#include <fplus/fplus.hpp>
#include <iostream>

int main()
{
    using namespace fplus;
    const std::string input(
                std::istreambuf_iterator<char>(std::cin.rdbuf()),
                std::istreambuf_iterator<char>());

    std::string output = fwd::apply(
                input,
                fwd::split_lines(false),
                fwd::sort(),
                fwd::join(std::string("\n")));

    std::cout << output << std::endl;
}
