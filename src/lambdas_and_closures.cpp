#include <fplus/fplus.hpp>
#include <iostream>

bool is_even(int x)
{
    return x % 2 == 0;
}

int main(int argc, char *argv[])
{
    std::vector<int> xs = {0, 1, 2, 3, 4};

    {
        const auto us = fplus::keep_if(is_even, xs);
        std::cout << "xs : " << fplus::show_cont(xs) << " -> is_even(xs) => us : " << fplus::show_cont(us) << std::endl;
    }

    // Lambda
    // [capture list] (parameters) -> return type
    // {
    //      body
    // }
    {
        const auto is_even = [](int x) -> bool
        {
            return x % 2 == 0;
        };
        const auto us = fplus::keep_if(is_even, xs);
        std::cout << "xs : " << fplus::show_cont(xs) << " -> is_even(xs) => us : " << fplus::show_cont(us) << std::endl;
    }

    // Anonymous Lambda function
    {
        const auto us = fplus::keep_if([](int x) -> bool
        {
            return x % 2 == 0;
        }, xs);
        std::cout << "xs : " << fplus::show_cont(xs) << " -> is_even(xs) => us : " << fplus::show_cont(us) << std::endl;
    }

    // Capture value
    {
        int val = 42;
        const auto add_value = [val](int x) -> int
        {
            return x + val;
        };
        const auto x = 10;
        const auto result = add_value(x);
        assert(result == val + x);
        std::cout << "add_value(x=" << x << "[, value=" << val << "]) = " << result << std::endl;
    }

    return 0;
}
