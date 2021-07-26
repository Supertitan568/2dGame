#include "object.h"
#include <iostream>
object::object (char type, int x, int y){
    pos[0] = x;
    pos[1] = y;
    switch (type){
        case 'M':
            size[0] = 32;
            size[1] = 32;
            if(!texture.loadFromFile("mario.png")){
                std::cerr << "ERROR: Mario.png could not be loaded";
            }
            sprite.setScale(.05, .05);
            break;
        case 'L':
            size[0] = 20;
            size[1] = 20;
            if(!texture.loadFromFile("LOZ_Textures.png", sf::IntRect(0,0,size[0],size[1]))){
                std::cerr << "ERROR: LOZ_Textures.png could not be loaded";
            }

        default:
            break;
    }
}