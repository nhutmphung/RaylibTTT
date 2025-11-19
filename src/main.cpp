#include <iostream>
#include <raylib.h>
#include <vector>
#include <string>
#include <random> 

#include "square.hpp"
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

                DrawRectangle(267, 50, 10, 500, BLACK);
                DrawRectangle(434, 50, 10, 500, BLACK);

                DrawRectangle(100, 217, 510, 10, BLACK);
                DrawRectangle(100, 380, 510, 10, BLACK);
                
            }
            

};

char randomXO() {
    return (rand() % 2 == 0) ? 'X' : 'O'; 
}


int main () {

    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 700;
    const int screenHeight = 600;


    SetTargetFPS(60);

    InitWindow(screenWidth, screenHeight, "Raylib Buttons!");

    Texture2D background = LoadTexture("assets/background.jpg");
    Button startButton{"assets/startButton.png", {300 ,75}, .50};
    Button endButton{"assets/exitButton.png",  {300 , 300}, .65};

    //TODO * 11/18/25 9:27pm, start creating board states and player turns. each player turn will populate the board state and after it populates, 
    //TODO * draw the image of an X or O along the center. with this, you can make the board state and the win condition as well 
    //TODO * look into creating an X object with two lines, look into making the lines thicker for the circle and the X (the x could just be two)
    vector<char> boardState (9, ' ');

    vector<Tile> squares = { 
        
    Tile ({100, 50}, 170 , WHITE),
    Tile ({270, 50}, 170 , WHITE),
    Tile ({440, 50}, 170 , WHITE),

    Tile ({120, 230}, 155 , WHITE),
    Tile ({280, 230}, 155 , WHITE),
    Tile ({440, 230}, 155 , WHITE),

    Tile ({120, 390}, 150 , WHITE),
    Tile ({280, 390}, 150 , WHITE),
    Tile ({440, 390}, 150 , WHITE)

    };



    Board board; 

    bool exit = false;


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------
    srand(time(NULL));
    char currentPlayer = randomXO();
    // Main game loop
    while (!WindowShouldClose() && !exit)    // Detect window close button or ESC key
    {

        Vector2 mousePosition = GetMousePosition(); 
        bool mousePressed = IsMouseButtonPressed(MOUSE_BUTTON_LEFT);

        // if(startButton.isPressed(mousePosition, mousePressed)) {
        //     cout << "Start button pressed" << endl; 
        // }
        // if(endButton.isPressed(mousePosition, mousePressed)) {
        //     exit = true;
        // }

        

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        //DrawTexture(background , 0 , 0, WHITE);
        ClearBackground(WHITE);
        //startButton.Draw();

        for(auto& s: squares){
            s.drawSquare();
        }

        for(int i = 0; i < squares.size(); i++) {

            Vector2 center = {
                squares[i].bounds.x + squares[i].bounds.width / 2,
                squares[i].bounds.y + squares[i].bounds.height / 2
            };

            if(squares[i].isHovered(mousePosition)) {
                squares[i].color = GRAY;
            }
            else {
                squares[i].color = WHITE;
            }

            if(squares[i].isHovered(mousePosition) && squares[i].isClicked(mousePosition, mousePressed)){
                cout << "Square " << (i + 1) << " clicked." << endl;

                if(boardState[i] == ' ') {
                    boardState[i] = currentPlayer; 
                    currentPlayer =  (currentPlayer == 'O') ? 'X' : 'O'; 
                    for(auto c: boardState) {
                        cout << c; 
                    }
                }
                DrawCircleLinesV({center.x, center.y} , 75, BLACK);
            }

        }

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