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

    // ┗ echo "Salut\nle\nMonde" | ./cli_with_compose
    // Monde
    // Salut
    // le
    cmd_line_interact(
                fwd::compose(
                    fwd::split_lines(false),
                    fwd::sort(),
                    fwd::join(std::string("\n"))
                    )
                );
}
