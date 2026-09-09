#pragma once

#include <stdint.h>

namespace ruezo {

    class HSV;

    class RGB {
    public:
        uint8_t r;
        uint8_t g;
        uint8_t b;

        RGB();
        RGB(uint8_t rr, uint8_t gg, uint8_t bb);

        ruezo::HSV toHSV();

        bool like(RGB other);
    };
}
