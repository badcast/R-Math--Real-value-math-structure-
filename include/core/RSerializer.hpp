#pragma once

#include "core.hpp"

namespace rmath {
   namespace core {

      template <typename T>
      class RSerializer {};

      template <>
      class RSerializer<::rmath::real8> {
            using target = rmath::real8;

         public:
            static void get_double(target* source, double* dest);
            static void get_float(target* source, float* dest);
            static void set_double(const double& source, target* dest);
            static void set_float(const float& source, target* dest);
            // signed section
            static void get_int8(target* source, std::int8_t* dest);
            static void get_int16(target* source, std::int16_t* dest);
            static void get_int32(target* source, std::int32_t* dest);
            static void get_int64(target* source, std::int64_t* dest);
            static void set_int8(const std::int8_t& source, target* dest);
            static void set_int16(const std::int16_t& source, target* dest);
            static void set_int32(const std::int32_t& source, target* dest);
            static void set_int64(const std::int64_t& source, target* dest);
            // unsigned section
            static void get_uint8(target* source, std::uint8_t* dest);
            static void get_uint16(target* source, std::uint16_t* dest);
            static void get_uint32(target* source, std::uint32_t* dest);
            static void get_uint64(target* source, std::uint64_t* dest);
            static void set_uint8(const std::uint8_t& source, target* dest);
            static void set_uint16(const std::uint16_t& source, target* dest);
            static void set_uint32(const std::uint32_t& source, target* dest);
            static void set_uint64(const std::uint64_t& source, target* dest);
      };

      template <>
      class RSerializer<::rmath::real16> {
            using target = rmath::real16;

         public:
      };
   }  // namespace core
}  // namespace rmath
