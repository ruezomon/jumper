#pragma once

#include <stdint.h>
#include "HSV.hpp"

namespace ruezo {
    class RGB {
    public:
    uint8_t r;
    uint8_t g;
    uint8_t b;

    RGB() : r(0), g(0), b(0) {}
    RGB(uint8_t rr, uint8_t gg, uint8_t bb) : r(rr), g(gg), b(bb) {}

    ruezo::HSV toHSV();

    inline bool like(RGB other) {
        return this->r == other.r && this->b == other.b && this->g == other.g;
    }

    };
}