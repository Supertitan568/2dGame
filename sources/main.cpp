#include "gameEngine.h"
gameEngine game;

int main () {
    if (game.init())
        game.runGame();
        return 0;
}
