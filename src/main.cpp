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
        vector<char> board; 
        public:


            Board() {
                vector<char> board (9, ' ');
                }

            void printBoard(void) {

                DrawRectangle(267, 50, 10, 500, BLACK);
                DrawRectangle(434, 50, 10, 500, BLACK);

                DrawRectangle(100, 217, 510, 10, BLACK);
                DrawRectangle(100, 380, 510, 10, BLACK);
                
            }

            bool checkWin(vector<char>& board, char player) {

                //** const int is used to maximized efficinecy here. a vector would work just as fine lol   */
                //* because we know that the win condition isn't going to change, we can make it an array with const int so that it doesnt change in size 
        
                const int wins[8][3] = {
                    {0,1,2}, //row 1 win con
                    {3,4,5}, //row 2 win con
                    {6,7,8}, //row 3 win con 
                    {0,3,6}, //col 1 win con
                    {1,4,7}, //col 2 win con 
                    {2,5,8}, //col 3 win con 
                    {0,4,8}, //diag 1 win con
                    {2,4,6} //diag 2 win con
                };

                for(auto& w : wins)  {
                    if ( board[w[0]] == player && board[w[1]] == player && board[w[2]] == player){
                        return true;
                    }
                }
                
                return false;
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

    //TODO * 5:23pm 11/19/2025 created boardStates and populated boardStates as well as alternating turns 

    //TODO * create it so that it makes the X and O graphic and create win condition. 

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