#include "tileMap.h"
#include <iostream>
bool tileMap::load(const std::string& tileset, sf::Vector2f tSTM, sf::Vector2u tStM , const int* tiles, unsigned int width, unsigned int height){
    if (!m_tileset.loadFromFile(tileset))
        return false;

    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    for (unsigned int h = 0; h < height; ++h)
        for (unsigned int w = 0; w < width; ++w){

            int tileNumber = tiles[w + h * width];
            sf::Vertex* quad = &m_vertices[(w + h * width) * 4];

            quad[0].position = sf::Vector2f(w * tSTM.x, h * tSTM.y);
            quad[1].position = sf::Vector2f((w + 1) * tSTM.x, h * tSTM.y);
            quad[2].position = sf::Vector2f((w + 1) * tSTM.x, (h + 1) * tSTM.y);
            quad[3].position = sf::Vector2f(w * tSTM.x, (h + 1) * tSTM.y);

            float offset;
            switch (tileNumber){
            case 0:
                offset = 0.f; 
                break;
            case 1:
                offset = 32.f;
                break;
            case 2:
                offset = 64.f;
                break;
            case 3:
                offset = 96.f;
                break;
            default:
                break;
            }
            quad[0].texCoords = sf::Vector2f(offset, 0.f);
            quad[1].texCoords = sf::Vector2f(32.f + offset, 0.f);
            quad[2].texCoords = sf::Vector2f(32.f + offset, 32.f);
            quad[3].texCoords = sf::Vector2f(offset, 32.f);

        }
    return true;
}
