#include <cstring>
#include <stdexcept>

#include "../../include/rmath.hpp"
#include "../../include/core/RSerializer.hpp"

using namespace rmath::core;
using namespace rmath::core::RSerializer;

enum RealContainerMask : char { MASK_NEGATIVE = 0x1, MASK_INT = 0x2 };

const uint32_t bitsArray[4][2] = {{0x1C>>2, 0xE0>>2}, {0x1fc>>2, 0xfe00>>2}, {0x1ffc>>2, 0xFFE000>>2}, {0x1FFFC>>2, 0xFFFE0000>>2}};

void get_member_real32(const int8_t* source, const std::size_t N, int& x, int &y){
   int z;
   if (N > sizeof(int)) throw std::runtime_error("sizeof N is big");

   x = 0;
   z = 2;  // z = 2 >------------------------------>|
   if (*source & RealContainerMask::MASK_INT) { //  |
      std::memcpy(&x, source, N);               //  |
      x >>= z;  // z is 2 -------------------------<|
      y = 1;                                    //  |
   } else {                                     //  |
      //formula:      N * 8 - 2                     |
      //          z = ----------, N > 0             |
      //                  2                         |
      // Дальнейшем оптимизировать этот блок кода.  |
      //todo: Оптимизировать                        |
      //                                            |
      z = (N * 8 - z) / z; // z is 2 --------------<|

      std::memcpy(&x, source, N);
      y= x >>= 2;
      x = x & bitsArray[N-1][0];
      y = y & bitsArray[N-1][1];
      y >>= N * z;
   }
   if ((*source) & RealContainerMask::MASK_NEGATIVE) x *= -1;
}


template <const std::size_t N>
inline void get_member_real32(const int8_t source[N], int& x, int& y) {
   get_member_real32(source, N, x, y);
}


template <const std::size_t N>
void get_member_real64(int8_t source[N], std::int64_t& x, std::int64_t& y);


void get_double(const target* source, double* dest) {
   int x;
   int y;
   if(dest == nullptr)
      throw std::runtime_error("param dest is null");
   get_member_real32(source->_buffer, target::size(), x, y);
   *dest = x / y; // calc
}
void R::get_float(const rmath::real8* source, float* dest) {}
void R::get_int8(const target* source, std::int8_t* dest) {}
void R::get_int16(const target* source, std::int16_t* dest) {}
void R::get_int32(const target* source, std::int32_t* dest) {}
void R::get_int64(const target* source, std::int64_t* dest) {}
void R::get_uint8(const target* source, std::uint8_t* dest) {}
void R::get_uint16(const target* source, std::uint16_t* dest) {}
void R::get_uint32(const target* source, std::uint32_t* dest) {}
void R::get_uint64(const target* source, std::uint64_t* dest) {}
void R::set_double(const double& source, target* dest) {}
void R::set_float(const float& source, target* dest) {}
void R::set_int8(const std::int8_t& source, target* dest) {}
void R::set_int16(const std::int16_t& source, target* dest) {}
void R::set_int32(const std::int32_t& source, target* dest) {}
void R::set_int64(const std::int64_t& source, target* dest) {}
void R::set_uint8(const std::uint8_t& source, target* dest) {}
void R::set_uint16(const std::uint16_t& source, target* dest) {}
void R::set_uint32(const std::uint32_t& source, target* dest) {}
void R::set_uint64(const std::uint64_t& source, target* dest) {}
