#pragma once

#include <stdint.h>
#include "RGB.hpp"

namespace ruezo {
   class Image {
   public:
      unsigned int w;
      unsigned int h;
      RGB *pixels;

      inline Image(unsigned int width, unsigned int height) : w(width), h(height) {
         pixels = new RGB[w * h];
      }

      inline ~Image() {
         delete[] pixels;
      }

      inline RGB &operator[](unsigned int index) {
         return pixels[index];
      }

   };
}
