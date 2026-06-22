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

    bool gameOver = false;

    void draw()
    {

        handleInput();

        block.update();

        handleCollisionLeft(block, wallLeft);
        handleCollisionRight(block, wallRight);
        handlePlatformsCollision();

        block.draw();
        wallLeft.draw();
        wallRight.draw();
        drawPlatforms();

        if (platforms.size() < 10)
        {
            generatePlatform();
        }

        while (!platforms.empty() && platforms.front().posY > windowHeight)
        {
            platforms.erase(platforms.begin());
        }

        if (block.posY < windowHeight / 2)
        {
            movePlatformsDown();
        }

        updateGameOver();
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

        if (isBlockWithin && a.velY >= 0.f)
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

        Block previousPlatform = platforms.back();
        Block newPlatform = { posX, previousPlatform.posY - posY , 100, 1, DARKBLUE };

        platforms.push_back(newPlatform);
    }

    void movePlatformsDown()
    {
        for (auto& p : platforms)
        {
            p.posY += 1;
        }
        generatePlatform();
    }

    void updateGameOver()
    {
        if (block.posY > windowHeight)
        {
            gameOver = true;
        }
    }
};
