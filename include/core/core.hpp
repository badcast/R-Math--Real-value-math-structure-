// Class for all real type base
#pragma once

#include <cstdint>

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
      template <typename T>
      class RSerializer;
      template <>
      class RSerializer<::rmath::real8>;
      template <>
      class RSerializer<::rmath::real16>;
      template <>
      class RSerializer<::rmath::real24>;
      template <>
      class RSerializer<::rmath::real32>;


      template <const int _size, typename _Derived>
      class realbase {  // abstract class
            using type = _Derived;

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
