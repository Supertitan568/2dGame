#include "gameEngine.h"
#include "object.h"
#include <SFML/OpenGL.hpp>
#include <vector>
std::vector<object> allObjects {object('L',10,10)};
void gameEngine::runGame(){
    init();
    while(window.isOpen()){
        pollWindowEvents();
        registerKeyPress();
        render();
    }
}

bool gameEngine::init (){
    allObjects[0].sprite.setTexture(allObjects[0].texture);
    if (!map.load("tileSet.png", sf::Vector2f(50,75),sf::Vector2u(32,32), level, 16, 8))
        return false;
    window.create(sf::VideoMode(800, 600), "2DGame");
    window.setVerticalSyncEnabled(true);
    window.setActive(true);
    return true;
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

void gameEngine::render (){
    window.clear(sf::Color::Black);
    window.draw(map);
    for(int o=0; o<allObjects.size(); o++){
        window.draw(allObjects[o].sprite);
    }
    window.display();
}

void gameEngine::registerKeyPress (){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        allObjects[0].pos[1]--;
        allObjects[0].sprite.setPosition(allObjects[0].pos[0], allObjects[0].pos[1]);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        allObjects[0].pos[0]--;
        allObjects[0].sprite.setPosition(allObjects[0].pos[0], allObjects[0].pos[1]);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        allObjects[0].pos[1]++;
        allObjects[0].sprite.setPosition(allObjects[0].pos[0], allObjects[0].pos[1]);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        allObjects[0].pos[0]++;
        allObjects[0].sprite.setPosition(allObjects[0].pos[0], allObjects[0].pos[1]);
    }    
}