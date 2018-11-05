int str_to_int(const std::string& str)
{
    int result;
    std::istringstream(str) >> result;
    return result;
}

double str_to_double(const std::string& str)
{
    double result;
    std::istringstream(str) >> result;
    return result;
}

// https://stackoverflow.com/questions/24084471/passing-stdplus-as-a-predicate
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2012/n3421.htm
template <template <typename> class PRED,
          typename T>
T parse_and_reduce(const std::string& input, const T init);
