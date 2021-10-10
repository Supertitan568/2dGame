#include "SFML/Graphics.hpp"
#include "tileMap.h"
#include "object.h"
#ifndef GAMEENGINE_H
#define GAMEENGINE_H

class gameEngine{
private:
    tileMap map;
    sf::RenderWindow window;
    std::vector<object> allObjects;

    void pollGameEvents();
    void render();
    void pollWindowEvents();
    void registerKeyPress();
public:
    bool init();
    void runGame();
    void shutdown();
};
#endif
