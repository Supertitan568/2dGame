#ifndef TILEMAP_H
#define TILEMAP_H

#include <SFML/Graphics.hpp>

class tileMap: public sf::Drawable, sf::Transformable{
private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const{
        states.transform *= getTransform();
        states.texture = &m_tileset;
        target.draw(m_vertices, states);
    }
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
public:
    bool load(const std::string& tileset, sf::Vector2f tSTM, sf::Vector2u tStM, const int* tiles, unsigned int width, unsigned int height);
    void loadLevel(std::string levelNum, int *loadingLevel);
    int level[128];
};
#endif