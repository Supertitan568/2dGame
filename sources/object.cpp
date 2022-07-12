#include "object.h"
#include <iostream>
object::object (char t, int x, int y){
    sprite.setPosition(x, y);
    switch (t){
        case 'L':
            type = t;

            size[0] = 15;
            size[1] = 16;

            if(!Stexture.loadFromFile("./bin/LOZ_Textures.png", sf::IntRect(0,0,size[0],size[1]))){
                std::cerr << "ERROR: LOZ_Textures.png could not be loaded";
            }
            if(!Atexture.loadFromFile("./bin/LOZ_Textures.png", sf::IntRect(30,0,size[0],size[1]))){
                std::cerr << "ERROR: LOZ_Textures.png could not be loaded";
            }
            if(!Wtexture.loadFromFile("./bin/LOZ_Textures.png", sf::IntRect(60,0,size[0],size[1]))){
                std::cerr << "ERROR: LOZ_Textures.png could not be loaded";
            }
            if(!Dtexture.loadFromFile("./bin/LOZ_Textures.png", sf::IntRect(90,0,size[0],size[1]))){
                std::cerr << "ERROR: LOZ_Textures.png could not be loaded";
            }

        default:
            break;
    }
}