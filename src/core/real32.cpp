#include "../../include/core/RSerializer.hpp"
#include "../../include/rmath.hpp"

using namespace rmath;
using namespace rmath::func;

using RS32 = rmath::core::RSerializer<real32>;

real32::real32() {}

real32::~real32() {}

real32::real32(const int& m, const int& p, const int& q) {
    this->m = m;
    this->p = p;
    this->q = q;
}
real32::real32(const int64_t& rhs) {
    this->m = 0;
    this->p = rhs;
    this->q = 1;
}
real32::real32(const uint64_t& rhs) {
    this->m = 0;
    this->p = rhs;
    this->q = 1;
}
real32::real32(const double& rhs) {
    if (rhs == std::numeric_limits<double>::infinity()) {
        *this = rmath::func::positiveInfinity;
    } else if (rhs == -std::numeric_limits<double>::infinity()) {
        *this = rmath::func::negativeInfinity;
    } else {
        m = 0;
        p = int(rhs * 1000) - int(rhs * 100);
        q = 900;
        *this = prime(*this);
    }
}

// function
real32& real32::one() {
    throw std::exception();
    return *this;
}

real32& real32::zero() {
    throw std::exception();
    return *this;
}

// operators

real32::operator const float() {
    return static_cast<float>(this->operator const double());
}
real32::operator const double() const {
    double val;
    RS32::get_double(this, &val);
    return val;
}

// signed section
real32::operator const std::int8_t() { return 0; }
real32::operator const std::int16_t() { return 0; }
real32::operator const std::int64_t() { return 0; }
real32::operator const std::int32_t() { return 0; }
// unsigned section
real32::operator const std::uint8_t() { return 0; }
real32::operator const std::uint16_t() { return 0; }
real32::operator const std::uint32_t() { return 0; }
real32::operator const std::uint64_t() { return 0; }
