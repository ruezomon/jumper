#include "FrameHandler.hpp"

FrameHandler::FrameHandler(int width, int height) : 
    img(ruezo::Image(height, width)), pixelBuffer(new int[width * height * 4]) {}

FrameHandler::~FrameHandler() {
    delete[] this->pixelBuffer;
}

ruezo::Image& FrameHandler::getImage() {
    return this->img;
}

int* FrameHandler::getPixelBuffer() {
    return this->pixelBuffer;
}