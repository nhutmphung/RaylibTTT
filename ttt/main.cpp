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
                DrawRectangle(250, 50, 10, 500, BLACK);
                DrawRectangle(450, 50, 10, 500, BLACK);
                DrawRectangle(100, 200, 500, 10, BLACK);
                DrawRectangle(100, 400, 500, 10, BLACK);
                
                DrawRectangle(250,200, 200,200 ,(Color){100, 0, 0, 120});
                DrawRectangle(50,200, 200,200 ,(Color){100, 0, 0, 120});
                DrawRectangle(450,200, 200,200 ,(Color){100, 0, 0, 120});

                DrawRectangle(250,50, 200,200 ,(Color){0, 0, 100, 120});
                DrawRectangle(50,50, 200,200 ,(Color){0, 0, 100, 120});
                DrawRectangle(450,50, 200,200 ,(Color){0, 0, 100, 120});
                

                DrawRectangle(250,350, 200,200 ,(Color){0, 100, 0, 120});
                DrawRectangle(50,350, 200,200 ,(Color){0, 100, 0, 120});
                DrawRectangle(450,350, 200,200 ,(Color){0, 100, 0, 120});
                
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
    const int screenWidth = 700;
    const int screenHeight = 600;

    SetTargetFPS(60);

    InitWindow(screenWidth, screenHeight, "Raylib Buttons!");

    Texture2D background = LoadTexture("ttt/graphics/background.jpg");
    Button startButton{"ttt/graphics/startButton.png", {300 ,75}, .50};
    Button endButton{"ttt/graphics/exitButton.png",  {300 , 300}, .65};
    Board board; 

    bool exit = false;


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    if(background.id == 0) {
        cout << "failed to load background" << endl;
    }
    // Main game loop
    while (!WindowShouldClose() && !exit)    // Detect window close button or ESC key
    {

        Vector2 mousePosition = GetMousePosition(); 
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        if(startButton.isPressed(mousePosition, mousePressed)) {
            cout << "Start button pressed" << endl; 
        }
        if(endButton.isPressed(mousePosition, mousePressed)) {
            exit = true;
        }


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        //ClearBackground(BLACK);
        //DrawTexture(background , 0 , 0, WHITE);
        ClearBackground(WHITE);
        //startButton.Draw();

        board.printBoard(); 
        //endButton.Draw();

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}