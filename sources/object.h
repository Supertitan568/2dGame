#ifndef OBJECT_H
#define OBJECT_H

#include "SFML/Graphics.hpp"

struct object{
    sf::Texture texture;
    int pos [2];
    int size [2];
    sf::Sprite sprite;
    object (char type, int x, int y);
};

#endif