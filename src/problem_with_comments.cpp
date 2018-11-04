#include <fplus/fplus.hpp>

int str_to_int(const std::string &str)
{
    int result;
    std::istringstream(str) >> result;
    return result;
}

int main()
{
    const std::string input = "1,5,4,7,2,2,3";
    const auto parts = fplus::split(',', false, input);
    const auto nums = fplus::transform(str_to_int, parts);

    // C++ 14
    const auto product = [](const auto &xs) {
        return fplus::reduce(std::multiplies<int>(), 1, xs);
    };

    const auto sum = [](const auto &xs) {
        return fplus::reduce(std::plus<int>(), 0, xs);
    };

    const auto result_for_product = product(nums);
    assert(result_for_product == 1 * 5 * 4 * 7 * 2 * 2 * 3);
    std::cout << result_for_product << std::endl;

    const auto result_for_sum = sum(nums);
    assert(result_for_sum == 1 + 5 + 4 + 7 + 2 + 2 + 3);
    std::cout << result_for_sum << std::endl;
}
