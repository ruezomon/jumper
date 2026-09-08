#pragma once

#include <stdint.h>
#include "RGB.hpp"

namespace ruezo {
   class HSV {
   public:
      float h;
      uint8_t s;
      uint8_t v;

      HSV() : h(0.0f), s(0), v(0) {}
      HSV(float hh, uint8_t ss, uint8_t vv) : h(hh), s(ss), v(vv) {}

      bool isGreen();
      bool isRed();
      bool isBlue();
      bool isYellow();
      bool isOrange();
      bool isCyan();
      bool isMagenta();
      bool isViolet();
      bool isBlack();
      bool isDarkGrey();
      bool isGrey();
      bool isWhite();

      ruezo::RGB getRGB();
      ruezo::RGB getRoughRGB();
      ruezo::RGB getNoColor();
   };
}

