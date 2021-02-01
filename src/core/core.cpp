#include "../../include/core/core.hpp"

namespace rmath {
   namespace core {

      enum RealContainerMask :char{
         MASK_POSITIVE = 0x0,
         MASK_NEGATIVE = 0x1,
         MASK_RESERVED1 = 0x2,
         MASK_RESERVED2 = 0x3
      };



   }  // namespace core
}  // namespace rmath
