#pragma once

#include <thread>
#include <vector>
#include <SFML/Graphics.hpp>

#include "Image.hpp"
#include "GameHandler.hpp"

namespace ruezo {
    class FrameHandler {
    private:
        ruezo::Image img;
        int* pixelBuffer;
        ruezo::GameHandler* gh = nullptr;
        int x = 0;
        int y = 0;
        double elapsed = 0.0f;
        std::thread* t = nullptr;
        bool t_flag = true;
        std::thread* dt = nullptr;

        sf::Texture texture;
        sf::Sprite sprite;
        sf::RenderWindow window;

    public:
        FrameHandler(int width, int height);
        ~FrameHandler();
        int* getPixelBuffer();
        ruezo::Image& getImage();
        void updateBuffer();
        void initGame(ruezo::GameHandler* gh);
        double getDeltaTime(); // returns delta time in seconds
        void display();
        std::thread* getDisplayThread();
    };
}
