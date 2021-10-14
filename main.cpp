#include "gameEngine.h"
#include <thread>

int main () {
    gameEngine* game = new gameEngine();
    if (game -> init()){
        std::thread renderThread(&gameEngine::runGameRender, game);
        game -> runGameLogic();
        renderThread.join();
    }
        return 0;
}
