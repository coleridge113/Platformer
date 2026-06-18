#pragma once

#include "block.h"
#include "constants.h"
#include "raylib.h"
#include <iostream>
#include <vector>

struct Game
{

    Block block { windowWidth / 2.f, floorY - 100, 30, 30, GRAY };

    std::vector<Block> platforms;

    Block wallLeft { 0, 0, 1, windowHeight, BLACK };
    Block wallRight { windowWidth, 0, 1, windowHeight, BLACK };
    Block floor { 0, floorY, windowWidth, 1, DARKBLUE };
    Block platform1 { 50, floorY - 40, 100, 1, DARKBLUE };
    Block platform2 { 300, floorY - 80, 100, 1, DARKBLUE };
    
    void draw()
    {
        platforms.push_back(platform1);
        platforms.push_back(platform2);

        handleInput();

        block.update();

        handleCollisionY(block, floor);
        handleCollisionLeft(block, wallLeft);
        handleCollisionRight(block, wallRight);
        handlePLatformsCollision();

        block.draw();
        floor.draw();
        wallLeft.draw();
        wallRight.draw();

        drawPlatforms();

    }

    void handleInput()
    {
        if (IsKeyPressed(KEY_SPACE))    block.jump();
        if (IsKeyDown(KEY_J))           block.move(-1, 0);
        if (IsKeyDown(KEY_L))           block.move(1, 0);
    }

    void handleCollisionY(Block& a, Block& b)
    {
        bool isBlockOnTop = (a.posY + a.height) >= b.posY &&
            a.posY < b.posY;
        bool isBlockWithin = 
            ((a.posX >= b.posX) && (a.posX <= (b.posX + b.width))) || 
            ((a.posX + a.width) >= b.posX && (a.posX + a.width) <= (b.posX + b.width));

        if (isBlockWithin && isBlockOnTop)
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

    void drawPlatforms()
    {
        for (const auto& platform : platforms)
        {
            platform.draw();
        }
    }

    void handlePLatformsCollision()
    {
        for (auto& platform : platforms)
        {
            handleCollisionY(block, platform);
        }
    }
};
