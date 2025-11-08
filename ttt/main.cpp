#include <iostream>
#include <raylib.h>
#include <vector>
#include <string>
#include "button.hpp"
//TODO * CRL + SHIFT + T to get file to COMPILE!!!

using namespace std;


class Board {
    private:
        int row;
        int column;
        char mark;
        vector <vector<char>> board;

        public:




            Board() {
                board = std::vector<std:: vector<char>> (3, std::vector<char>(3, ' '));
            }

            void printBoard(void) {
                //does this really need to be adde...?
            }

            int placeMark() {
                //let the cursor place on the mark 
            }

            bool checkWin(){
                //same logic as before in terms of the vector
            }
            bool checkDraw() {
                //same logic as before in terms of the c++ file 
            }

            void gameStart() {
                //same logic as before, but switches between 'x' and 'o' after every turn

            }

};



int main () {

    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 800;

    SetTargetFPS(60);

    InitWindow(screenWidth, screenHeight, "Raylib Buttons!");

    Texture2D background = LoadTexture("graphics/background.avif");
    Button startButton{"graphics/startutton.png", {300 ,150}, .65};
    Button endButton{"graphics/endButton.png",  {300 ,150}, .65};

    bool exit = false;


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose() == false && exit == false)    // Detect window close button or ESC key
    {

        Vector2 mousePosition = GetMousePosition(); 
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if(startButton.isPressed(mousePosition, mousePressed)) {
            cout << "Start button pressed" << endl; 
        }
        if(endButton.isPressed(mousePosition, mousePressed)) {
            exit == true;
        }


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            ClearBackground(BLACK);


            DrawTexture(background , 0 , 0, WHITE);
            DrawCircle(50,50,50,RED);
            startButton.Draw();
            endButton.Draw();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}