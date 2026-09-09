#include "Player.hpp"
#include "InitializeException.hpp"

ruezo::Player::Player(int w, int h, int x, int y) : w(w), h(h), x(x), y(y) {}

void ruezo::Player::linkGame(GameHandler* gh) {
    if (this->game == nullptr) this->game = gh;
    else throw ruezo::InitializeException("player can only be linked to one game", 1);
}