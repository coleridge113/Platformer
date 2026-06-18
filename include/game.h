#pragma once

#include "block.h"
#include "constants.h"
#include "raylib.h"
#include <iostream>

struct Game
{

    Block block { windowWidth / 2.f, floorY - 100, 30, 30, GRAY };
    Block floor { 0, floorY, windowWidth, 1, DARKBLUE };

    void draw()
    {
        handleInput();

        block.update();
        handleCollision(block, floor);

        block.draw();
        floor.draw();

    }

    void handleInput()
    {
        int keyPressed = GetKeyPressed();

        switch (keyPressed)
        {
            case KEY_SPACE:
                block.jump();
                break;
            default:
                break;
        }
    }

    void handleCollision(Block& a, Block& b)
    {
        float bottomA = a.y + a.height;
        if (bottomA >= b.y)
        {
            a.velocity = 0;
            a.y = b.y - a.height;
        }
    }
};
