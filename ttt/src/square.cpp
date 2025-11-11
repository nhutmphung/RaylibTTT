#include "square.hpp"

Tile::Tile(Vector2 position, float size) 
    :bounds{ position.x , position.y, size, size}, mark(' ') {}


void Tile::drawSquare() const {
    DrawRectangleRec(bounds, (Color) {20, 100, 100, 100});
}

bool Tile::isHovered(Vector2 mousePos) const {
     return CheckCollisionPointRec(mousePos, bounds); 
}

// bool Tile::isClicked(Vector2 mousePos, bool mousePressed) {
//     if (CheckCollisionPointRec(mousePos, bounds) && mousePressed) {
//         return true;
//     }
//     return false;
// }

void Tile::setMark(char m)  {
    mark = m;
};
