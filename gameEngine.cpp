#include "gameEngine.h"
#include <SFML/OpenGL.hpp>
#include <vector>
#include <iostream>

void gameEngine::runGameRender(){
    while(window.isOpen()){
        render();
        pollWindowEvents();
        registerKeyPress();
    }
}

void gameEngine::runGameLogic(){
    while(window.isOpen()){
        pollGameEvents();
    }
}

void gameEngine::pollGameEvents(){
    sf::Vector2f pos = allObjects[0].sprite.getPosition();
    if(pos.y == 600){
        map.loadLevel("2",map.level);
        allObjects[0].sprite.setPosition(pos.x, 0);
        std::cout << pos.y << '\n';
        map.load("tileSet.png", sf::Vector2f(50,75),sf::Vector2u(32,32), map.level, 16, 8);    
    }
}

bool gameEngine::init (){
    allObjects.push_back(object('L',10,10));
    allObjects[0].sprite.setTexture(allObjects[0].Stexture);
    map.loadLevel("1",map.level);
    if (!map.load("tileSet.png", sf::Vector2f(50,75),sf::Vector2u(32,32), map.level, 16, 8))
        return false;
    window.create(sf::VideoMode(800, 600), "2DGame");
    window.setVerticalSyncEnabled(true);
    window.setActive(true);
    return true;
}

void gameEngine::render (){
    window.clear(sf::Color::Black);
    window.draw(map);
    for(int o=0; o<allObjects.size(); o++){
        window.draw(allObjects[o].sprite);
    }
    window.display();
}

void gameEngine::pollWindowEvents (){
    sf::Event event;
    while (window.pollEvent(event)){
        switch (event.type){
            case sf::Event::Closed:
                window.close();
                break;
            default:
                break;
        }
    }
}

void gameEngine::registerKeyPress (){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        allObjects[0].sprite.setTexture(allObjects[0].Wtexture);
        allObjects[0].sprite.move(0,-1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        allObjects[0].sprite.setTexture(allObjects[0].Atexture);
        allObjects[0].sprite.move(-1,0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        allObjects[0].sprite.setTexture(allObjects[0].Stexture);
        allObjects[0].sprite.move(0,1);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        allObjects[0].sprite.setTexture(allObjects[0].Dtexture);
        allObjects[0].sprite.move(1,0);
    }    
}

