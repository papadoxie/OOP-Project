#pragma once
#include <stdint.h>

//Contains values of different colors
struct Colors
{ //*                               R           G           B
    const uint32_t BLACK    = 0   << 16  | 0   << 8  | 0   << 0  ;
    const uint32_t WHITE    = 255 << 16  | 255 << 8  | 255 << 0  ;
    const uint32_t PURPLE   = 108 << 16  | 36  << 8  | 171 << 0  ;
    const uint32_t GREEN    = 80  << 16  | 255 << 8  | 0   << 0  ;
    const uint32_t RED      = 255 << 16  | 0   << 8  | 0   << 0  ;
    const uint32_t PINK     = 255 << 16  | 0   << 8  | 200 << 0  ;
    const uint32_t BLUE     = 0   << 16  | 0   << 8  | 255 << 0  ;
    const uint32_t GREY     = 90  << 16  | 90  << 8  | 90  << 0  ;
};