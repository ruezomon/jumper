#include <cmath>

#include "RGB.hpp"

ruezo::HSV ruezo::RGB::toHSV() {
    enum COLORS {r, g, b};
    float h;
    uint8_t s;
    uint8_t v;
    double rr = this->r / 255.0f;
    double gg = this->g / 255.0f;
    double bb = this->b / 255.0f;
    double channels[3] = {rr, gg, bb};
    int cmax;
    if (rr >= gg && rr >= bb) cmax = COLORS::r;
    else if (gg >= rr && gg >= bb) cmax = COLORS::g;
    else cmax = COLORS::b;
    int cmin;
    if (rr <= gg && rr <= bb) cmin = COLORS::r;
    else if (gg <= bb && gg <= rr) cmin = COLORS::g;
    else cmin = COLORS::b;
    double maxVal = channels[cmax];
    double minVal = channels[cmin];
    double delta = maxVal - minVal;

    if (delta == 0) h = 0.0f;
    else if (cmax == COLORS::r) h = 60 * fmod((((gg - bb) / delta)), 6);
    else if (cmax == COLORS::g) h = 60 * (((bb - rr) / delta) + 2);
    else h = 60 * (((rr - gg) / delta) + 4);
    if (h < 0) h += 360;

    s = (maxVal == 0) ? 0 : static_cast<uint8_t>((delta / maxVal) * 255);

    v = static_cast<uint8_t>(maxVal * 255);

    return HSV(h, s, v);
}