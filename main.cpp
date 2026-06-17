#include "raylib.h"
#include "classes/block.h"

constexpr int windowWidth = 500;
constexpr int windowHeight = 620;
constexpr int targetFPS = 60;

Block block { 250, 300, 50, 50, GRAY };

void handleInput()
{
    if (IsKeyPressed(KEY_SPACE))
    {
        block.jump();
    }
}

int main()
{
    InitWindow(windowWidth, windowHeight, "Platformer");
    SetTargetFPS(targetFPS);

    while (!WindowShouldClose())
    {
        handleInput();
        block.update();

        BeginDrawing();
        ClearBackground(BLACK);

        block.draw();

        EndDrawing();
    }

    CloseWindow();
}
