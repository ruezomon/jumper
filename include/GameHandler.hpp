#pragma once

namespace ruezo {
    class FrameHandler;
    class Player;

    class GameHandler {
    private:
        int* gameArray;
        int playerOrigin[2] = {0, 0};

        ruezo::FrameHandler* fh;
        ruezo::Player* p;

    public:
        GameHandler(int width, int height);
    };
}