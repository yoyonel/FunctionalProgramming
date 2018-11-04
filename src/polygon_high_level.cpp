#include <fplus/fplus.hpp>

int main(int argc, char const *argv[])
{
    using namespace std;

    typedef std::pair<float, float> point;

    const vector<point> polygon =
        {{1, 2}, {7, 3}, {6, 5}, {4, 4}, {2, 9}};

    const auto point_distance2 = [](const auto &p1, const auto &p2) {
        const float dx = p2.first - p1.first;
        const float dy = p2.second - p1.second;
        const float d2 = (dx * dx) + (dy * dy);
        return d2;
    };

    const auto edge_length = [point_distance2](const auto &edge) {
        return point_distance2(edge.first, edge.second);
    };

    const auto get_edges = [](const auto &polygon) {
        return fplus::overlapping_pairs_cyclic(polygon);
    };

    // more higher level of abstraction for computing the result -> edge_length, get_edges (fplus::maximum_on)
    // more consise
    const auto result = fplus::maximum_on(edge_length, get_edges(polygon));

    cout << fplus::show(result) << endl;

    return 0;
}