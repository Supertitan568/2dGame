#include "SFML/Graphics.hpp"
#include "tileMap.h"
#ifndef GAMEENGINE_H
#define GAMEENGINE_H

class gameEngine{
private:
    void pollWindowEvents();
    sf::RenderWindow window;
    void render ();
    void registerKeyPress();
    int *loadLevel(int levelNum);
    tileMap map;
public:
    bool init();
    void runGame();
    void shutdown();
};
#endif
