#pragma once 
#include <raylib.h>

class Tile {
    public: 
        Tile(Vector2 position, float size); 
        //dont need deconstructor cause it's not loading texture
        
        void drawSquare() const;
        bool isHovered(Vector2 mousePos) const; //const is used after the function so the function doesn't modify object data, helps protect obect 
        void setMark(char m); 
        char getMark() const;
        // bool isClicked(Vector2 mousePos, bool mousePressed);


    private: 
    Rectangle bounds; 
    char mark; 
};

