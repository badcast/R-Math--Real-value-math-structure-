#pragma once

#include "core.hpp"

namespace rmath {
    namespace core {
        namespace RSerializer {
            template <typename target>
            static void get_double(const target* source, double* dest);
            template <typename target>
            static void get_float(const target* source, float* dest);
            template <typename target>
            static void set_double(const double& source, target* dest);
            template <typename target>
            static void set_float(const float& source, target* dest);
            template <typename target>
            // signed section template<typename target>
            static void get_int8(const target* source, std::int8_t* dest);
            template <typename target>
            static void get_int16(const target* source, std::int16_t* dest);
            template <typename target>
            static void get_int32(const target* source, std::int32_t* dest);
            template <typename target>
            static void get_int64(const target* source, std::int64_t* dest);
            template <typename target>
            static void set_int8(const std::int8_t& source, target* dest);
            template <typename target>
            static void set_int16(const std::int16_t& source, target* dest);
            template <typename target>
            static void set_int32(const std::int32_t& source, target* dest);
            template <typename target>
            static void set_int64(const std::int64_t& source, target* dest);
            template <typename target>
            // unsigned section template<typename target>
            static void get_uint8(const target* source, std::uint8_t* dest);
            template <typename target>
            static void get_uint16(const target* source, std::uint16_t* dest);
            template <typename target>
            static void get_uint32(const target* source, std::uint32_t* dest);
            template <typename target>
            static void get_uint64(const target* source, std::uint64_t* dest);
            template <typename target>
            static void set_uint8(const std::uint8_t& source, target* dest);
            template <typename target>
            static void set_uint16(const std::uint16_t& source, target* dest);
            template <typename target>
            static void set_uint32(const std::uint32_t& source, target* dest);
            template <typename target>
            static void set_uint64(const std::uint64_t& source, target* dest);
        }  // namespace RSerializer
    }  // namespace core
}  // namespace rmath
