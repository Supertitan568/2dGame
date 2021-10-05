#include "object.h"
#include <iostream>
object::object (char t, int x, int y){
    sprite.setPosition(x, y);
    switch (t){
        case 'M':
            size[0] = 32;
            size[1] = 32;
            if(!Stexture.loadFromFile("mario.png")){
                std::cerr << "ERROR: Mario.png could not be loaded";
            }
            sprite.setScale(.05, .05);
            break;
        case 'L':
            type = t;

            size[0] = 15;
            size[1] = 16;

            if(!Stexture.loadFromFile("LOZ_Textures.png", sf::IntRect(0,0,size[0],size[1]))){
                std::cerr << "ERROR: LOZ_Textures.png could not be loaded";
            }
            if(!Atexture.loadFromFile("LOZ_Textures.png", sf::IntRect(30,0,size[0],size[1]))){
                std::cerr << "ERROR: LOZ_Textures.png could not be loaded";
            }
            if(!Wtexture.loadFromFile("LOZ_Textures.png", sf::IntRect(60,0,size[0],size[1]))){
                std::cerr << "ERROR: LOZ_Textures.png could not be loaded";
            }
            if(!Dtexture.loadFromFile("LOZ_Textures.png", sf::IntRect(90,0,size[0],size[1]))){
                std::cerr << "ERROR: LOZ_Textures.png could not be loaded";
            }

        default:
            break;
    }
}