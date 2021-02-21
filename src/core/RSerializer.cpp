#include <cstring>

#include "../../include/rmath.hpp"

using namespace rmath::core;

enum RealContainerMask : char { MASK_NEGATIVE = 0x1, MASK_INT = 0x2 };

template <int N>
void get_member_real(int8_t source[N], int& x, int& y) {
   int z = 2, i, w;  // z = 2
   if (N > sizeof(int)) {
      throw std::bad_exception();
   }
   x = 0;
   if (((*source) & RealContainerMask::MASK_INT)) {
      std::memcpy(&x, source, N);
      x >>= z;  // z = 2
      y = 1;
   } else {
      z = (N * 8 - z) / z;  // get center, z = 2
      w = 1;
      i=0;
      do {
         // write left and right
         x |= source[i];

         w *= z;

      } while (w < z);

      do {
      } while (false);
   }
   if ((*source) & RealContainerMask::MASK_NEGATIVE) x *= -1;
}

void set_member_real();  //

template <int N>
void get_member_real_ll(int8_t source[N], std::int64_t& x, std::int64_t& y) {}

// ---------------------- R8
using RS8 = RSerializer<rmath::real8>;  // using
void RS8::get_double(target* source, double* dest) {}
void RS8::get_float(rmath::real8* source, float* dest) {}
void RS8::get_int8(target* source, std::int8_t* dest) {}
void RS8::get_int16(target* source, std::int16_t* dest) {}
void RS8::get_int32(target* source, std::int32_t* dest) {}
void RS8::get_int64(target* source, std::int64_t* dest) {}
void RS8::get_uint8(target* source, std::uint8_t* dest) {}
void RS8::get_uint16(target* source, std::uint16_t* dest) {}
void RS8::get_uint32(target* source, std::uint32_t* dest) {}
void RS8::get_uint64(target* source, std::uint64_t* dest) {}
void RS8::set_double(const double& source, target* dest) {}
void RS8::set_float(const float& source, target* dest) {}
void RS8::set_int8(const std::int8_t& source, target* dest) {}
void RS8::set_int16(const std::int16_t& source, target* dest) {}
void RS8::set_int32(const std::int32_t& source, target* dest) {}
void RS8::set_int64(const std::int64_t& source, target* dest) {}
void RS8::set_uint8(const std::uint8_t& source, target* dest) {}
void RS8::set_uint16(const std::uint16_t& source, target* dest) {}
void RS8::set_uint32(const std::uint32_t& source, target* dest) {}
void RS8::set_uint64(const std::uint64_t& source, target* dest) {}

// ---------------------- R16

// ---------------------- R24

// ---------------------- R32

// ---------------------- R64
