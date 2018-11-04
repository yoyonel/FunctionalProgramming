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
        const auto is_even = [](int x) -> bool {
            return x % 2 == 0;
        };
        const auto us = fplus::keep_if(is_even, xs);
        std::cout << "xs : " << fplus::show_cont(xs) << " -> is_even(xs) => us : " << fplus::show_cont(us) << std::endl;
    }

    // Anonymous Lambda function
    {
        const auto us = fplus::keep_if([](int x) -> bool {
            return x % 2 == 0;
        },
                                       xs);
        std::cout << "xs : " << fplus::show_cont(xs) << " -> is_even(xs) => us : " << fplus::show_cont(us) << std::endl;
    }

    // Capture value
    {
        int val = 42; // val out of the scope of lambda

        // capture by value
        const auto add_value = [val](int x) -> int {
            return x + val;
        };

        // capture by reference
        // val inside the body that's affect by mutation to val outside the body
        const auto add_value_ref = [&val](int x) -> int {
            return x + val;
        };

        // C++ 14
        // Deducing type parameter and return
        const auto add_value_cpp14 = [val](auto x) {
            return x + val;
        };

        const int x = 10;

        // by value
        {
            auto result = add_value(x);
            assert(result == 42 + x);
            std::cout << "add_value(x=" << x << "[, value=" << val << "]) = " << result << std::endl;

            // mutate val outside the body of lambda
            val = 32;
            std::cout << "mutate val (outside of the lambda body) -> val = " << val << std::endl;
            result = add_value(x);
            assert(result == 42 + x); // no modification of the result -> the val capture isn't affect by mutation
            std::cout << "add_value(x=" << x << "[, value=" << val << "]) = " << result << std::endl;
        }

        // by reference
        {
            val = 42;
            auto result = add_value_ref(x);
            assert(result == 42 + x);
            std::cout << "add_value_ref(x=" << x << "[, value=" << val << "]) = " << result << std::endl;

            // mutate val outside the body of lambda
            val = 32;
            std::cout << "mutate val (outside of the lambda body) -> val = " << val << std::endl;
            result = add_value_ref(x);
            assert(result == 32 + x); // the val mutation (outside of the body) affect the lambda
            std::cout << "add_value_ref(x=" << x << "[, value=" << val << "]) = " << result << std::endl;
        }

        // C++ 14
        {
            val = 42;
            auto result = add_value_cpp14(x);
            assert(result == 42 + x);
            std::cout << "add_value_cpp14(x=" << x << "[, value=" << val << "]) = " << result << std::endl;
        }
    }

    return 0;
}
