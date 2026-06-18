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
        if (IsKeyPressed(KEY_SPACE))
        {
            block.jump();
        }

        if (IsKeyDown(KEY_J))
        {
            block.move(-1, 0);
        }

        if (IsKeyDown(KEY_L))
        {
            block.move(1, 0);
        }
    }

    void handleCollision(Block& a, Block& b)
    {
        float bottomA = a.posY + a.height;
        if (bottomA >= b.posY)
        {
            a.velY = 0;
            a.posY = b.posY - a.height;
            a.isJumping = false;
        }
    }

    void handleMovement(int keyPressed)
    {
        
    }
};
