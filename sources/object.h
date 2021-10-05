#ifndef OBJECT_H
#define OBJECT_H

#include "SFML/Graphics.hpp"

struct object{
    sf::Sprite sprite;

    sf::Texture Wtexture;
    sf::Texture Atexture;
    sf::Texture Stexture;
    sf::Texture Dtexture;

    char type;
    int size[2];
    int offset[2];

    object (char t, int x, int y);
};

#endif