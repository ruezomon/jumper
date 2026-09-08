#include "FrameHandler.hpp"

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
