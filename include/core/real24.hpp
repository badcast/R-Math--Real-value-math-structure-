#pragma once
#include "core.hpp"
#include "real8.hpp"
#include "real16.hpp"
#include "real32.hpp"

namespace rmath{
    class real24 : public core::realbase<3>{
        public: 
        real24();
        ~real24();
        // operators
        operator float();
        operator double();

        // signed section
        operator std::int8_t();
        operator std::int16_t();
        operator std::int64_t();
        operator std::int32_t();
        // unsigned section
        operator std::uint8_t();
        operator std::uint16_t();
        operator std::uint32_t();
        operator std::uint64_t();
    } real24_t;
}
