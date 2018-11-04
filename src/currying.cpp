#include <fplus/fplus.hpp>

// add : (Int, Int) -> Int
int add(int a, int b)
{
    return a + b;
}

// add_3 : Int -> Int
int add_3(int b)
{
    return add(3, b);
}

// add_curried : Int -> (Int -> Int)
// => add_curried : Int -> Int -> Int
std::function<int(int)> add_curried(int a)
{
    return [a](int b) {
        return a + b;
    };
}

bool is_even(int x)
{
    return x % 2 == 0;
}

int main(int argc, char const *argv[])
{
    using namespace std;

    // application: calling function add
    cout << "add(3, 4) = " << add(3, 4) << endl;

    std::vector<int> xs = {0, 1, 2, 3, 4};
    const auto xs_add3 = fplus::transform(add_3, xs);
    cout << "transform(add_3, xs = " << fplus::show(xs) << ") = " << fplus::show(xs_add3) << endl;
    // xs == {3, 4, 5, 6, 7};

    // transform(bind_1st_of_2(add, 3), xs);

    cout << "add_curried(3)(4) = " << add_curried(3)(4) << endl;

    const auto xs_curried_add3 = fplus::transform(add_curried(3), xs);
    cout << "transform(add_curried(3), xs = " << fplus::show(xs) << ") = " << fplus::show(xs_curried_add3) << endl;

    std::vector<std::vector<int>> xss = {{0, 1, 2}, {3, 4, 5}};

    // const auto &xss_even = fplus::transform(fplus::keep_if(is_even), xss); // can't work, arity error
    // keep_if : ((a -> bool), [a]) -> [a]
    // we need a currying version to this
    // const auto &xss_even = fplus::transform(keep_if_c(is_even), xss);
    // fplus::fwd::keep_if : (a -> bool) -> [a] -> [a]
    const auto &xss_even = fplus::transform(fplus::fwd::keep_if(is_even), xss);
    cout << "Keep even from xss(= " << fplus::show(xss) << ") = " << fplus::show(xss_even) << endl;

    // Square the numbers in container xss
    const auto &xss_square = fplus::transform(fplus::fwd::transform(fplus::square<int>), xss);
    cout << "Square(xss) = " << fplus::show(xss_square) << endl;

    // a + b + c + d
    const auto add_four_curried = [](int a) {
        return [a](int b) {
            return [a, b](int c) {
                return [a, b, c](int d) {
                    return a + b + c + d;
                };
            };
        };
    };
    assert(add_four_curried(1)(2)(3)(4) == 1 + 2 + 3 + 4);

    return 0;
}
