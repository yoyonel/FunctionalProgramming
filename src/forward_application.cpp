#include <fplus/fplus.hpp>

typedef std::pair<float, float> point;
typedef std::pair<point, point> edge;
typedef std::vector<point> points;

float point_distance(const point &p1, const point &p2)
{
    const float dx = p2.first - p1.first;
    const float dy = p2.second - p1.second;
    return std::sqrt(dx * dx + dy * dy);
}

float point_distance2(const point &p1, const point &p2)
{
    const float dx = p2.first - p1.first;
    const float dy = p2.second - p1.second;
    return dx * dx + dy * dy;
}

float edge_length(const edge &e)
{
//    return point_distance(e.first, e.second);
    return point_distance2(e.first, e.second);
}

std::vector<edge> get_edges(const points &polygon)
{
    return fplus::overlapping_pairs_cyclic(polygon);
}

int main()
{
    using namespace std;

    vector<point> polygon =
        {{1, 2}, {7, 3}, {6, 5}, {4, 4}, {2, 9}};

    const auto result = fplus::fwd::apply(
        polygon,
        get_edges,
        fplus::fwd::maximum_on(edge_length));

    cout << fplus::show(result) << endl;
}
