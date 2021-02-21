// Class for all real type base
#pragma once

#include <cstdint>
#include "RSerializer.hpp"

namespace rmath {
    class real8;
    class real16;
    class real24;
    class real32;
    class real64;

    namespace func {
        template <typename type>
        struct get_value;

        template <>
        struct get_value<::rmath::real8>;

        template <>
        struct get_value<::rmath::real16>;

        template <>
        struct get_value<::rmath::real24>;

        template <>
        struct get_value<::rmath::real32>;

    }  // namespace func
}  // namespace rmath

namespace rmath {

    namespace core {

        namespace RSerializer{
            template <typename target>
            static void RSerializer::get_double(const target* source, double* dest);
            template <typename target>
            static void RSerializer::get_float(const target* source, float* dest);
            template <typename target>
            static void RSerializer::set_double(const double& source, target* dest);
            template <typename target>
            static void RSerializer::set_float(const float& source, target* dest);
            template <typename target>
            // signed section template<typename target>
            static void RSerializer::get_int8(const target* source, std::int8_t* dest);
            template <typename target>
            static void RSerializer::get_int16(const target* source, std::int16_t* dest);
            template <typename target>
            static void RSerializer::get_int32(const target* source, std::int32_t* dest);
            template <typename target>
            static void RSerializer::get_int64(const target* source, std::int64_t* dest);
            template <typename target>
            static void RSerializer::set_int8(const std::int8_t& source, target* dest);
            template <typename target>
            static void RSerializer::set_int16(const std::int16_t& source, target* dest);
            template <typename target>
            static void RSerializer::set_int32(const std::int32_t& source, target* dest);
            template <typename target>
            static void RSerializer::set_int64(const std::int64_t& source, target* dest);
            template <typename target>
            // unsigned section template<typename target>
            static void RSerializer::get_uint8(const target* source, std::uint8_t* dest);
            template <typename target>
            static void RSerializer::get_uint16(const target* source, std::uint16_t* dest);
            template <typename target>
            static void RSerializer::get_uint32(const target* source, std::uint32_t* dest);
            template <typename target>
            static void RSerializer::get_uint64(const target* source, std::uint64_t* dest);
            template <typename target>
            static void RSerializer::set_uint8(const std::uint8_t& source, target* dest);
            template <typename target>
            static void RSerializer::set_uint16(const std::uint16_t& source, target* dest);
            template <typename target>
            static void RSerializer::set_uint32(const std::uint32_t& source, target* dest);
            template <typename target>
            static void RSerializer::set_uint64(const std::uint64_t& source, target* dest);
        }

        template <const std::size_t _size, typename _Derived>
        class realbase {  // abstract class
                using type = _Derived;

                template <typename target>
                friend static void RSerializer::get_double(const target* source, double* dest);
                template <typename target>
                friend static void RSerializer::get_float(const target* source, float* dest);
                template <typename target>
                friend static void RSerializer::set_double(const double& source, target* dest);
                template <typename target>
                friend static void RSerializer::set_float(const float& source, target* dest);
                template <typename target>
                // signed section template<typename target>
                friend static void RSerializer::get_int8(const target* source, std::int8_t* dest);
                template <typename target>
                friend static void RSerializer::get_int16(const target* source, std::int16_t* dest);
                template <typename target>
                friend static void RSerializer::get_int32(const target* source, std::int32_t* dest);
                template <typename target>
                friend static void RSerializer::get_int64(const target* source, std::int64_t* dest);
                template <typename target>
                friend static void RSerializer::set_int8(const std::int8_t& source, target* dest);
                template <typename target>
                friend static void RSerializer::set_int16(const std::int16_t& source, target* dest);
                template <typename target>
                friend static void RSerializer::set_int32(const std::int32_t& source, target* dest);
                template <typename target>
                friend static void RSerializer::set_int64(const std::int64_t& source, target* dest);
                template <typename target>
                // unsigned section template<typename target>
                friend static void RSerializer::get_uint8(const target* source, std::uint8_t* dest);
                template <typename target>
                friend static void RSerializer::get_uint16(const target* source, std::uint16_t* dest);
                template <typename target>
                friend static void RSerializer::get_uint32(const target* source, std::uint32_t* dest);
                template <typename target>
                friend static void RSerializer::get_uint64(const target* source, std::uint64_t* dest);
                template <typename target>
                friend static void RSerializer::set_uint8(const std::uint8_t& source, target* dest);
                template <typename target>
                friend static void RSerializer::set_uint16(const std::uint16_t& source, target* dest);
                template <typename target>
                friend static void RSerializer::set_uint32(const std::uint32_t& source, target* dest);
                template <typename target>
                friend static void RSerializer::set_uint64(const std::uint64_t& source, target* dest);

                friend class ::rmath::core::RSerializer<::rmath::real8>;
                friend class ::rmath::core::RSerializer<::rmath::real16>;
                friend class ::rmath::core::RSerializer<::rmath::real24>;
                friend class ::rmath::core::RSerializer<::rmath::real32>;

                friend struct ::rmath::func::get_value<::rmath::real8>;
                friend struct ::rmath::func::get_value<::rmath::real16>;
                friend struct ::rmath::func::get_value<::rmath::real24>;
                friend struct ::rmath::func::get_value<::rmath::real32>;

            protected:
                int8_t _buffer[_size];

            public:
                static const std::size_t size() { return _size; }
        };
    }  // namespace core
}  // namespace rmath
