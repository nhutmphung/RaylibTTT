#include "square.hpp"

Tile::Tile(Vector2 position, float size, Color color) {
    bounds = { position.x, position.y, size, size };
    this->color = color;
    mark = ' ';
}
    

void Tile::drawSquare() const {
    DrawRectangleRec(bounds, color);
}

bool Tile::isHovered(Vector2 mousePos) const {
     return CheckCollisionPointRec(mousePos, bounds); 
}

bool Tile::isClicked(Vector2 mousePos, bool mousePressed) {
    if (CheckCollisionPointRec(mousePos, bounds) && mousePressed) {
        return true;
    }
    return false;
}

void Tile::setMark(char m)  {
    mark = m;
};

char Tile::getMark() const {
    return mark;
}
