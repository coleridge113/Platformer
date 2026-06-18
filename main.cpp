#include "include/game.h"
#include "raylib.h"
#include "include/constants.h"


int main()
{
    InitWindow(windowWidth, windowHeight, "Platformer");
    SetTargetFPS(targetFPS);

    Game game {};

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(BLACK);

        {
            game.draw();
        }

        EndDrawing();
    }

    CloseWindow();
}
