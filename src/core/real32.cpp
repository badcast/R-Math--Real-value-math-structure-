#include "../../include/rmath.hpp"
#include "../../include/core/real32.hpp"

using namespace rmath;

real32::real32(const int& m, const int& p, const int& q)
{
    this->m = m;
    this->p = p;
    this->q = q;
}
real32::real32(const int64_t& rhs)
{
    this->m = 0;
    this->p = rhs;
    this->q = 1;
}
real32::real32(const uint64_t& rhs)
{
    this->m = 0;
    this->p = rhs;
    this->q = 1;
}
real32::real32(const double& rhs)
{
    if (rhs == std::numeric_limits<double>::infinity()) {
        *this = positiveInfinity;
    } else if (rhs == -std::numeric_limits<double>::infinity()) {
        *this = negativeInfinity;
    } else {
        m = 0;
        p = int(rhs * 1000) - int(rhs * 100);
        q = 900;
        *this = to_prime(*this);
    }
}

real32::operator double() { return to_double(*this); }
