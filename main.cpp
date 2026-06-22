#include "include/game.h"
#include "raylib.h"
#include "include/constants.h"


int main()
{
    InitWindow(windowWidth, windowHeight, "Platformer");
    SetTargetFPS(targetFPS);

    Game game {};
    Font font = GetFontDefault();

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(BLACK);

        {
            game.draw();

            if (game.gameOver)
            {
                DrawTextEx(font, "Game Over", 
                        { (windowWidth / 2) - 70, (windowHeight / 2) - 80 }, 
                        32, 2, WHITE);

                if (GetKeyPressed() != 0)
                {
                    game = Game {};
                }
            }
        }

        EndDrawing();
    }

    CloseWindow();
}
