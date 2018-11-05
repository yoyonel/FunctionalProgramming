#include <cassert>
#include <vector>
//
#include <fplus/fplus.hpp>

bool is_even(int x)
{
    return x % 2 == 0;
}

template <typename Pred, typename Cont>
Cont keep_if(Pred pred, Cont &xs)
{
    Cont ys;
    for (const auto x : xs)
    {
        if (pred(x))
        {
            ys.push_back(x);
        }
    }
    return ys;
}

int main()
{
    std::vector<int> xs = {0, 1, 2, 3, 4};

    const auto ys = keep_if(is_even, xs);
    assert(ys == std::vector<int>({0, 2, 4}));
    std::cout << "is_even with manual keep_if: " << fplus::show_cont(xs) << " => " << fplus::show_cont(ys) << std::endl;

    const auto ys_fp = fplus::keep_if(is_even, xs);
    assert(ys_fp == std::vector<int>({0, 2, 4}));
    std::cout << "is_even with fplus keep_if: " << fplus::show_cont(xs) << " => " << fplus::show_cont(ys_fp) << std::endl;
}
