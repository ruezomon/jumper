#include "FrameHandler.hpp"
#include "RGB.hpp"
#include "InitializeException.hpp"

ruezo::FrameHandler::FrameHandler(int width, int height, int pixelSize) : 
    img(ruezo::Image(height, width)), pixelBuffer(new int[width * height * 4]), 
    sprite(sf::Sprite(texture)), 
    window(sf::RenderWindow(sf::VideoMode({static_cast<uint8_t>(width), static_cast<uint8_t>(height)}), "Jumper", sf::Style::Close)),
    pixelSize(pixelSize) {
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

void ruezo::FrameHandler::updateBuffer() {
    for (int i = 0; i < img.w; i++) {
        ruezo::RGB& im = img[i];
        pixelBuffer[i * 4    ] = static_cast<uint8_t>(im.r);
        pixelBuffer[i * 4 + 1] = static_cast<uint8_t>(im.g);
        pixelBuffer[i * 4 + 2] = static_cast<uint8_t>(im.b);
        pixelBuffer[i * 4 + 3] = 255;
    }
    texture.update(std::vector<uint8_t>(pixelBuffer, pixelBuffer + (sizeof(pixelBuffer) / sizeof(pixelBuffer[0]))).data());
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

void ruezo::FrameHandler::display() {
    this->dt = new std::thread([this]() {
        while (this->window.isOpen()) {
            while (const std::optional event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>()) {
                    window.close();
                }
            }

            this->updateBuffer();

            window.clear(sf::Color::Black);
            window.draw(sprite);
            window.display();
        }
    });
    this->dt->detach();
}

std::thread* ruezo::FrameHandler::getDisplayThread() {
    return this->dt;
}
