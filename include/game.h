#pragma once

#include "block.h"
#include "constants.h"
#include "raylib.h"
#include "utils.h"
#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <vector>

struct Game
{

    Block block { windowWidth / 2.f, floorY - 100, 30, 30, GRAY };

    std::vector<Block> platforms {
        Block{ 0, floorY, windowWidth, 1, DARKBLUE },
    };

    Block wallLeft { 0, 0, 1, windowHeight, BLACK };
    Block wallRight { windowWidth, 0, 1, windowHeight, BLACK };

    Block floor = platforms[0];

    void draw()
    {

        handleInput();

        block.update();

        handleCollisionY(block, floor);
        handleCollisionLeft(block, wallLeft);
        handleCollisionRight(block, wallRight);
        handlePlatformsCollision();

        block.draw();
        floor.draw();
        wallLeft.draw();
        wallRight.draw();

        drawPlatforms();

        if (platforms.size() < 10)
        {
            generatePlatform();
        }
    }

    void handleInput()
    {
        if (IsKeyPressed(KEY_SPACE))    block.jump();
        if (IsKeyDown(KEY_J))           block.move(-1, 0);
        if (IsKeyDown(KEY_L))           block.move(1, 0);
    }

    void handleCollisionY(Block& a, Block& b)
    {
        bool isBlockWithin = (a.posX < b.posX + b.width) && ((a.posX + a.width) > b.posX);

        if (isBlockWithin)
        {
            if (a.velY >= 0.f)
            {
                float prevBottom = a.posY + a.height - (a.velY - gravity);
                if (prevBottom <= b.posY && (a.posY + a.height) >= b.posY)
                {
                    a.velY = 0.f;
                    a.posY = b.posY - a.height;
                    a.isJumping = false;
                }
            }
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

    void handlePlatformsCollision()
    {
        for (auto& platform : platforms)
        {
            handleCollisionY(block, platform);
        }
    }

    void generatePlatform()
    {
        float posX = generateRandom(20, 380);
        float posY = generateRandom(70, 100);

        Block previousPlatform = platforms[platforms.size() - 1];
        Block newPlatform = { posX, previousPlatform.posY - posY , 100, 1, DARKBLUE };

        platforms.push_back(newPlatform);
    }
};
