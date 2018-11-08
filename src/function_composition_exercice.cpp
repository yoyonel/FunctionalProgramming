#include <fplus/fplus.hpp>

double str_to_double(const std::string& str)
{
    double result = NAN;
    std::istringstream(str) >> result;
    return result;
}

int main()
{
    using namespace fplus;

    const std::string input = "1,5,4,7,2,2,3.34";

    const auto result = fplus::fwd::apply(input
        , fplus::fwd::split(',', false)
        , fplus::fwd::transform(str_to_double)
        , fplus::fwd::product()
    );

    std::cout << result << std::endl;

    const auto parse_and_product = fplus::fwd::compose(
           fplus::fwd::split(',', false),
           fplus::fwd::transform(str_to_double),
           fplus::fwd::product());
    const auto result_with_composition = parse_and_product(input);
    assert(result_with_composition == result);

    std::cout << result_with_composition << std::endl;
}
