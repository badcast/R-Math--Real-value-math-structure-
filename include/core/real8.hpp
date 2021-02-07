#pragma once

#include "core.hpp"

namespace rmath {
   // real8 contained void* type
   typedef class real8 : public core::realbase<0b0001, real8> {
      public:
         real8();
         explicit real8(const int& x);
         explicit real8(const int& x, const int& y);
         explicit real8(const int& x, const int& y, const int& z);
         explicit real8(const float& x);
         explicit real8(const double& x);
         explicit real8(const real16& rhs);
         explicit real8(const real24& rhs);
         explicit real8(const real32& rhs);

         real8& zero();
         real8& one() ;

         operator const float();
         operator const double();

         // signed section
         operator const std::int8_t();
         operator const std::int16_t();
         operator const std::int64_t();
         operator const std::int32_t();

         // unsigned section
         operator const std::uint8_t();
         operator const std::uint16_t();
         operator const std::uint32_t();
         operator const std::uint64_t();

         operator bool();

         static const real8 e;

   } real8_t, real_low_t;

}  // namespace rmath
