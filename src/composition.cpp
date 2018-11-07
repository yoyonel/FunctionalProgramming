#include <fplus/fplus.hpp>

const auto str_to_int = fplus::read_value_unsafe<int>;

int square_int(int x)
{
    return x * x;
}

int main(int, char *[])
{
    using namespace fplus;

    std::vector<std::string> inputs = {"2", "3", "4"};

    // 2 loops (transform) for str parsing to int and compute squaring integer
    const auto result = fwd::apply(
        inputs,
        fwd::transform(str_to_int),
        fwd::transform(square_int),
        fwd::sum());
    assert(result == 2 * 2 + 3 * 3 + 4 * 4);
    std::cout << "sum(square(input = " << show(inputs) << ") = " << show(result) << std::endl;

    // Composition can help to mutualize loops
    const auto parse_and_square =
        fwd::compose(str_to_int, square_int);
    const auto result_with_composition =
        fwd::apply(
            inputs,
            fwd::transform(parse_and_square),
            fwd::sum());
    assert(result_with_composition == result);
    std::cout << "with composition - sum(square(input = "
              << show(inputs) << ") = "
              << show(result_with_composition)
              << std::endl;

    return 0;
}
