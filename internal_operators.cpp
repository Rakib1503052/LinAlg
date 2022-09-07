#include "internal.hpp"

std::vector<double> operator-(const std::vector<double>& vec1, const std::vector<double>& vec2)
{
    size_t n = vec1.size();
    std::vector<double> ret(n);
    for (size_t i = 0; i < n; i++)
    {
        ret[i] = vec1[i] - vec2[i];
    }
    return ret;
}

std::vector<double> operator*(const double coef, const std::vector<double>& vec2)
{
    size_t n = vec2.size();
    std::vector<double> ret(n);
    for (size_t i = 0; i < n; i++)
    {
        ret[i] = coef * vec2[i];
    }
    return ret;
}
