// "Correctness follows from expressiveness."
// xs -> ys == [0, 1, 2, 3, 4] -> [0, 1, 4, 9, 16]
#include <algorithm>
#include <chrono>
#include <iostream>
#include <iterator>
#include <vector>
#include <vector>
//
#include <fplus/fplus.hpp>

using namespace std;

typedef vector<int> Ints;

class Timer
{
  public:
    Timer() : beg_(clock::now()) {}
    void reset() { beg_ = clock::now(); }
    double elapsed() const
    {
        return std::chrono::duration_cast<second>(clock::now() - beg_).count();
    }

  private:
    typedef std::chrono::high_resolution_clock clock;
    typedef std::chrono::duration<double, std::ratio<1>> second;
    std::chrono::time_point<clock> beg_;
};

int square(int x)
{
    return x * x;
}

Ints square_vec_goto(const Ints &xs)
{
    Ints ys;
    ys.reserve(xs.size());
    auto it = begin(xs);
loopBegin:
    if (it == end(xs))
        goto loopEnd;
    ys.push_back(square(*it));
    ++it;
    goto loopBegin;
loopEnd:
    return ys;
}

Ints square_vec_while(const Ints &xs)
{
    Ints ys;
    ys.reserve(xs.size());
    auto it = begin(xs);
    while (it != end(xs))
    {
        ys.push_back(square(*it));
        ++it;
    }
    return ys;
}

Ints square_vec_for(const Ints &xs)
{
    Ints ys;
    ys.reserve(xs.size());
    for (auto it = begin(xs); it != end(xs); ++it)
    {
        ys.push_back(square(*it));
    }
    return ys;
}

Ints square_vec_range_based_for(const Ints &xs)
{
    Ints ys;
    ys.reserve(xs.size());
    // C++ 11
    for (int x : xs)
    {
        ys.push_back(square(x));
    }
    return ys;
}

Ints square_vec_std_transform(const Ints &xs)
{
    Ints ys;
    ys.reserve(xs.size());
    transform(begin(xs), end(xs),
              back_inserter(ys), square);
    return ys;
}

// FP
// transform_vec is higher-function
template <typename F, typename T>
vector<T> transform_vec(F f, const vector<T> &xs)
{
    vector<T> ys;
    ys.reserve(xs.size());
    transform(begin(xs), end(xs), back_inserter(ys), f);
    return ys;
}

Ints square_vec_transform_vec(const Ints &xs)
{
    return transform_vec(square, xs);
}

Ints square_vec_fplus_transform(const Ints &xs)
{
    // Generic container support
    return fplus::transform(square, xs);
}

template <typename F, typename T>
double timer_on(F f, const vector<T> &xs)
{
    Timer stopwatch;
    for (int i = 0; i < 1 << 16; i++)
    {
        f(xs);
    }
    return stopwatch.elapsed();
}

int main()
{
    Ints xs(1 << 13);

    cout << "goto: " << timer_on(square_vec_goto, xs) << " s" << endl;
    cout << "while: " << timer_on(square_vec_while, xs) << " s" << endl;
    cout << "for: " << timer_on(square_vec_for, xs) << " s" << endl;
    cout << "range based for: " << timer_on(square_vec_range_based_for, xs) << " s" << endl;
    cout << "std transform: " << timer_on(square_vec_std_transform, xs) << " s" << endl;
    cout << "transform vec: " << timer_on(square_vec_transform_vec, xs) << " s" << endl;
    cout << "fplus transform: " << timer_on(square_vec_fplus_transform, xs) << " s" << endl;
}
