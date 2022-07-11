#include "gameEngine.h"
#include <SFML/OpenGL.hpp>
#include <vector>
#include<iostream>

void gameEngine::runGame(){
    while(window.isOpen()){
        pollWindowEvents();
        pollGameEvents();
        registerKeyPress();
        render();
    }
}

void gameEngine::pollGameEvents(){
    sf::Vector2f pos = allObjects[0].sprite.getPosition();
    if(pos.y == 600){
        levelNumY -= 1;
        std::string levelNum = std::to_string(levelNumX) + std::to_string(levelNumY);
        map.loadLevel(levelNum ,map.level);
        allObjects[0].sprite.setPosition(pos.x, 1);
        map.load("tileSet.png", sf::Vector2f(50,75),sf::Vector2u(32,32), map.level, 16, 8);    
    }
    else if(pos.y == 0){
        levelNumY += 1;
        std::string levelNum = std::to_string(levelNumX) + std::to_string(levelNumY);
        map.loadLevel(levelNum ,map.level);
        allObjects[0].sprite.setPosition(pos.x, 599);
        map.load("tileSet.png", sf::Vector2f(50,75),sf::Vector2u(32,32), map.level, 16, 8);
    }
    else if(pos.x == 800){
        levelNumX += 1;
        std::string levelNum = std::to_string(levelNumX) + std::to_string(levelNumY);
        map.loadLevel(levelNum ,map.level);
        allObjects[0].sprite.setPosition(1, pos.y);
        map.load("tileSet.png", sf::Vector2f(50,75),sf::Vector2u(32,32), map.level, 16, 8);
    }
    else if(pos.x == 0){
        levelNumX -= 1;
        map.loadLevel(std::to_string(levelNumX) + std::to_string(levelNumY) ,map.level);
        allObjects[0].sprite.setPosition(799, pos.y);
        map.load("tileSet.png", sf::Vector2f(50,75),sf::Vector2u(32,32), map.level, 16, 8);
    }
}

bool gameEngine::init (){
    allObjects.push_back(object('L',10,10));
    allObjects[0].sprite.setTexture(allObjects[0].Stexture);
    levelNumX = 0;
    levelNumY = 0;
    std::string levelNum = std::to_string(levelNumX) + std::to_string(levelNumY);
    map.loadLevel(levelNum,map.level);
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

