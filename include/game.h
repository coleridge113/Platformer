#pragma once

#include "block.h"
#include "constants.h"
#include "raylib.h"
#include <iostream>

struct Game
{

    Block block { windowWidth / 2.f, floorY - 100, 30, 30, GRAY };

    Block wallLeft { 0, 0, 1, windowHeight, BLACK };
    Block wallRight { windowWidth, 0, 1, windowHeight, BLACK };
    Block floor { 0, floorY, windowWidth, 1, DARKBLUE };

    void draw()
    {
        handleInput();

        block.update();
        handleCollisionY(block, floor);
        handleCollisionLeft(block, wallLeft);
        handleCollisionRight(block, wallRight);

        block.draw();
        floor.draw();
        wallLeft.draw();
        wallRight.draw();

    }

    void handleInput()
    {
        if (IsKeyPressed(KEY_SPACE))    block.jump();
        if (IsKeyDown(KEY_J))           block.move(-1, 0);
        if (IsKeyDown(KEY_L))           block.move(1, 0);
    }

    void handleCollisionY(Block& a, Block& b)
    {
        float bottomA = a.posY + a.height;
        if (bottomA >= b.posY)
        {
            a.velY = 0;
            a.posY = b.posY - a.height;
            a.isJumping = false;
        }
    }

    void handleCollisionLeft(Block& a, Block& b)
    {
        float left = a.posX;

        if (left <= b.posX)
        {
            a.posX = b.posX;
        }
    }

    void handleCollisionRight(Block& a, Block& b)
    {
        float rightA = a.posX + a.width;

        if (rightA >= b.posX)
        {
            a.posX = b.posX -  a.width;
        }
    }
};
