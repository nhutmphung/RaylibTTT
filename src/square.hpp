#pragma once
#include <raylib.h>

class Tile {
public:
    Rectangle bounds;
    Color color;

    Tile(Vector2 position, float size, Color color);   // ONLY declare

    void drawSquare() const;
    bool isHovered(Vector2 mousePos) const;
    bool isClicked(Vector2 mousePos, bool mousePressed);
    void setMark(char m);
    char getMark() const;

private:
    char mark;
};
