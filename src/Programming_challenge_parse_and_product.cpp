#include <fplus/fplus.hpp>
#include "Programming_challenge_parse_and_product.hpp"

template <template <typename> class PRED>
double parse_and_reduce(const std::string& input, const double init)
{
    const auto parts = fplus::split(',', false, input);
    const auto nums =
        fplus::transform(str_to_double, parts);

    const auto result = fplus::reduce(PRED<double>(), init, nums);
    return result;
}

template <template <typename> class PRED>
int parse_and_reduce(const std::string& input, const int init)
{
    const auto parts = fplus::split(',', false, input);
    const auto nums =
        fplus::transform(str_to_int, parts);

    const auto result = fplus::reduce(PRED<int>(), init, nums);
    return result;
}

int main()
{
    const std::string input = "1.5,5,4,7.5,2,2,3";

    // Integers values
    // product
    {
        const auto result = parse_and_reduce<std::multiplies>(input, 1);
        assert(result == 1*5*4*7*2*2*3);
        std::cout << result << std::endl;
    }
    // addition
    {
        const auto result = parse_and_reduce<std::plus>(input, 0);
        assert(result == 1+5+4+7+2+2+3);
        std::cout << result << std::endl;
    }

    // Floating values
    // product
    {
        const auto result = parse_and_reduce<std::multiplies>(input, 1.0);
        assert(result == 1.5*5*4*7.5*2*2*3);
        std::cout << result << std::endl;
    }

    // addiction
    {
        const auto result = parse_and_reduce<std::plus>(input, 0.0);
        assert(result == 1.5+5+4+7.5+2+2+3);
        std::cout << result << std::endl;
    }
}
