#include <fplus/fplus.hpp>

int main()
{
    const int a = 3;

    // intermediate values
    const int b = fplus::square(a);
    const int c = fplus::min_2(2, b);
    const int d = fplus::abs_diff(7, c);
    const int e = fplus::clamp(1, 4, d);
    const int f = fplus::max_2(6, e);
    std::cout << f << std::endl;

    // nested function calls
    const int f_nested = fplus::max_2(
        6,
        fplus::clamp(
            1, 4,
            fplus::abs_diff(
                7,
                fplus::min_2(2, fplus::square(a)))));
    std::cout << f_nested << std::endl;

    // foward-application style
    const int f_fwd = fplus::fwd::apply(
        a,
        fplus::fwd::square(),
        fplus::fwd::min_2(2),
        fplus::fwd::abs_diff(7),
        fplus::fwd::clamp(1, 4),
        fplus::fwd::max_2(6));
    std::cout << f_fwd << std::endl;

    assert(f == 6);
    assert(f == f_nested);
    assert(f_nested == f_fwd);

    return 0;
}
