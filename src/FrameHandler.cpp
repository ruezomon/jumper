#include "FrameHandler.hpp"
#include "RGB.hpp"

ruezo::FrameHandler::FrameHandler(int width, int height) : 
    img(ruezo::Image(height, width)), pixelBuffer(new int[width * height * 4]) {}

ruezo::FrameHandler::~FrameHandler() {
    delete[] this->pixelBuffer;
}

ruezo::Image& ruezo::FrameHandler::getImage() {
    return this->img;
}

int* ruezo::FrameHandler::getPixelBuffer() {
    return this->pixelBuffer;
}

void ruezo::FrameHandler::updateBuffer() {
    for (int j = 0; j < img.h; j++) {
        for (int i = 0; i < img.w; i++) {
            ruezo::RGB& im = img[i + (j * img.w)];
            pixelBuffer[(i + j * img.w) * 4] = im.r;
            pixelBuffer[(i + j * img.w) * 4 + 1] = im.g;
            pixelBuffer[(i + j * img.w) * 4 + 2] = im.b;
            pixelBuffer[(i + j * img.w) * 4 + 3] = 255;
        }
    }
}