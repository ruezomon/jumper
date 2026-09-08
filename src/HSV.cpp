#include <string>
#include <map>
#include <functional>
#include <cmath>

#include "RGB.hpp"
#include "HSV.hpp"

ruezo::HSV::HSV() : h(0.0f), s(0), v(0) {}

ruezo::HSV::HSV(float hh, uint8_t ss, uint8_t vv) : h(hh), s(ss), v(vv) {}

bool ruezo::HSV::isGreen() {
    return s > 100 && h >= 70 && h < 160;
}

bool ruezo::HSV::isRed() {
    return s > 100 && h >= 330 || h < 15;
}

bool ruezo::HSV::isBlue() {
    return s > 100 && h >= 210 && h < 235;
}

bool ruezo::HSV::isYellow() {
    return s > 100 && h >= 45 && h < 70;
}

bool ruezo::HSV::isOrange() {
    return s > 100 && h >= 15 && h < 45;
}

bool ruezo::HSV::isCyan() {
    return s > 100 && h >= 160 && h < 210;
}

bool ruezo::HSV::isMagenta() {
    return s > 100 && h >= 285 && h < 330;
}

bool ruezo::HSV::isViolet() {
    return s > 100 && h >= 235 && h < 285;
}

bool ruezo::HSV::isBlack() { // dont even dare to return #000000
    return s <= 100 && v <= 70;
}

bool ruezo::HSV::isDarkGrey() {
    return s <= 100 && v <= 120 && v > 70;
}

bool ruezo::HSV::isGrey() {
    return s <= 100 && v <= 180 && v > 120;
}

bool ruezo::HSV::isWhite() { // pls dont actually return #ffffff :sob:
    return s <= 100 && v > 180;
}

ruezo::RGB ruezo::HSV::getRGB() {
   std::function d = [](float f) { if (f < 0.0f) return 0.0f; else if (f > 1.0f) return 1.0f; else return f; };
   float ss = d(s / 255.0f);
   float vv = d(v / 255.0f);
   float hh = std::fmod(h, 360.0f);

   if (hh < 0.0f) hh += 360;

   double c = vv * ss;
   double x = c * (1.0 - std::fabs(std::fmod(h / 60.0, 2.0) - 1.0));
   double m = vv - c;

   double rPrime = 0.0;
   double gPrime = 0.0;
   double bPrime = 0.0;

   if (h < 60.0) {
      rPrime = c;
      gPrime = x;
   } else if (h < 120.0) {
      rPrime = x;
      gPrime = c;
   } else if (h < 180.0) {
      gPrime = c;
      bPrime = x;
   } else if (h < 240.0) {
      gPrime = x;
      bPrime = c;
   } else if (h < 300.0) {
      rPrime = x;
      bPrime = c;
   } else {
      rPrime = c;
      bPrime = x;
   }

   return ruezo::RGB(static_cast<int>(std::round((rPrime + m) * 255.0)), static_cast<int>(std::round((gPrime + m) * 255.0)), static_cast<int>(std::round((bPrime + m) * 255.0)));
}

// no map lookups for speed, but needs update if map does change
ruezo::RGB ruezo::HSV::getRoughRGB() {
   if (isRed()) return ruezo::RGB(255, 0, 0);
   if (isGreen()) return ruezo::RGB(0, 255, 40);
   if (isBlue()) return ruezo::RGB(0, 0, 255);
   if (isYellow()) return ruezo::RGB(255, 255, 0);
   if (isCyan()) return ruezo::RGB(0, 255, 255);
   if (isMagenta()) return ruezo::RGB(255, 0, 255);
   if (isOrange()) return ruezo::RGB(255, 165, 0);
   if (isViolet()) return ruezo::RGB(0x79, 0x21, 0xb1);
   if (isBlack()) return ruezo::RGB(1, 2, 3);
   if (isDarkGrey()) return ruezo::RGB(36, 36, 36);
   if (isGrey()) return ruezo::RGB(169, 169, 169);
   if (isWhite()) return ruezo::RGB(238, 238, 238);
   return RGB(0, 0, 0);
}

ruezo::RGB ruezo::HSV::getNoColor() {
   ruezo::RGB inv = HSV(this->h, 0, this->v).getRGB();
   return ruezo::RGB(255 - inv.r, 255 - inv.g, 255 - inv.b);
}