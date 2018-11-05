#include <fplus/fplus.hpp>
#include <iostream>

// cmd_line_interact : (String -> String) -> ()
// () = nothing
template <typename F>
void cmd_line_interact(F f)
{
    std::cout << f(std::string(
                       std::istreambuf_iterator<char>(std::cin.rdbuf()),
                       std::istreambuf_iterator<char>())) << std::endl;
}

int main()
{
    using namespace fplus;

    // ┗ echo "Salut le monde\!" | ./cli
    // SALUT LE MONDE!
    cmd_line_interact(fwd::to_upper_case());
}
