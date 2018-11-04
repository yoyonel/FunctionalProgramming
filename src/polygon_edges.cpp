#include <fplus/fplus.hpp>

typedef std::pair<float, float> point;

float point_distance(const point &p1, const point &p2)
{
    const float dx = p2.first - p1.first;
    const float dy = p2.second - p2.second;
    return std::sqrt(dx * dx + dy * dy);
}

float point_distance2(const point &p1, const point &p2)
{
    const float dx = p2.first - p1.first;
    const float dy = p2.second - p1.second;
    return dx * dx + dy * dy;
}

int main(int argc, char const *argv[])
{
    using namespace std;

    vector<point> polygon =
        {{1, 2}, {7, 3}, {6, 5}, {4, 4}, {2, 9}};

    // Find the longest edge of the polygon

    // adjacent_pairs: [a] -> [(a, a)]
    // adjacent_pairs([0,1,2,3,4]) == [(0,1),(2,3)]

    // overlapping_pairs : [a] -> [(a, a)]
    // overlapping_pairs([0,1,2,3]) == [(0,1),(1,2),(2,3)]

    // (*) What we need ^^
    // overlapping_pairs_cyclic : [a] -> [(a, a)]
    // overlapping_pairs_cyclic([0,1,2,3]) == [(0,1),(1,2),(2,3),(3,0)]^

    const auto edges =
        fplus::overlapping_pairs_cyclic(polygon);

    // maximum_on : ((a -> b), [a]) -> a
    // maximum_on(length, ["123", "12", "1234", "123"]) == "1234"

    // < C++14
    {
        const auto result = fplus::maximum_on(
            [](const std::pair<point, point> &edge) -> float {
                return point_distance(edge.first, edge.second);
                // return point_distance2(edge.first, edge.second);
            },
            edges);
        cout << fplus::show(result) << endl;
    }

    // C++ 14
    {
        const auto result =
            fplus::maximum_on(
                [](const auto &edge) {
                    // return point_distance(edge.first, edge.second);
                    return point_distance2(edge.first, edge.second);
                },
                edges);
        cout << fplus::show(result) << endl;
    }

    return 0;
}
