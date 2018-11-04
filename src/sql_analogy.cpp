#include <fplus/fplus.hpp>

struct user
{
    std::string name;
    std::string country;
    std::size_t visits;
};

std::string get_country(const user& u)
{
    return u.country;
}

std::size_t get_visits(const user& u)
{
    return u.visits;
}

int main(int argc, char *argv[])
{
    using namespace std;

    const std::vector<user> users = {
        {"Nicole", "GER", 2},
        {"Justin", "USA", 1},
        {"Rachel", "USA", 5},
        {"Robert", "FRA", 6},
        {"Stefan", "GER", 4}
    };

    // Find the sum visits number of each country
    //  GER, 6
    //  USA, 6
    //  FRA, 6
    // in SQL =>
    // SELECT country, SUM(visits)
    //  FROM users
    //  GROUP BY country;

    // In C++, using the following functions:
    // - group_globally_on_labeled : ((a -> b), [a]) -> [(b, [a])]
    // - transform_snd : ((b -> c), (a, b)) -> (a, c)
    // - mean : [a] -> a
    const auto visit_sum = [](const std::vector<user>& xs) -> std::size_t
    {
        return fplus::fwd::apply(xs
                                 , fplus::fwd::transform(get_visits)
                                 , fplus::fwd::sum());
    };
    //    cout << "visit_sum(users) = " << visit_sum(users) << endl;

    // group_globally_on_labeled : O(n²)
    const auto result = fplus::fwd::apply(
                users,
                fplus::fwd::group_globally_on_labeled(get_country), // O(n²)
                fplus::fwd::transform(fplus::fwd::transform_snd(visit_sum)));
    std::cout << fplus::show_cont(result) << std::endl;

    // n * log(n)
    // sort_on: n * log(n)
    // group_on_labeled: n * log(n)
    const auto result_n_log_n = fplus::fwd::apply(
                users,
                fplus::fwd::sort_on(get_country),   // O(nlog(n))
                fplus::fwd::group_on_labeled(get_country),  // O(nlog(n))
                fplus::fwd::transform(fplus::fwd::transform_snd(visit_sum)));
    std::cout << fplus::show_cont(result_n_log_n) << std::endl;

    return 0;
}

