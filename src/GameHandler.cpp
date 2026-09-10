#include "GameHandler.hpp"
#include "FrameHandler.hpp"
#include "Player.hpp"

ruezo::GameHandler::GameHandler(int width, int height) : gameArray(new int[width * height]), p(new ruezo::Player(10, 10)) {}

void ruezo::GameHandler::startGame() {
    fh = new ruezo::FrameHandler(800, 600);
    
}