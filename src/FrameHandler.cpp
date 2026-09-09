#include "FrameHandler.hpp"
#include "InitializeException.hpp"

ruezo::FrameHandler::FrameHandler(int width, int height) : 
    img(ruezo::Image(height, width)), pixelBuffer(new int[width * height * 4]) {
        this->t = new std::thread([this]() {
            while (this->t_flag) {
                this->elapsed += 0.01;
                std::this_thread::sleep_for(std::chrono::milliseconds(10));
            }
        });
        this->t->detach();
    }

ruezo::FrameHandler::~FrameHandler() {
    delete[] this->pixelBuffer;
    this->t_flag = false;
    delete this->t;
}

ruezo::Image& ruezo::FrameHandler::getImage() {
    return this->img;
}

int* ruezo::FrameHandler::getPixelBuffer() {
    return this->pixelBuffer;
}

void ruezo::FrameHandler::initGame(ruezo::GameHandler* gh) {
    if (this->gh == nullptr) this->gh = gh;
    else throw ruezo::InitializeException("GameHandler can only be initialized once", 2);
}

double ruezo::FrameHandler::getDeltaTime() {
    double r = this->elapsed;
    this->elapsed = 0.0f;
    return r;
}
