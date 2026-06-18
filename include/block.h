#pragma once

#include "raylib.h"
#include "constants.h"

struct Block 
{
    static constexpr int jumpForce = -10;
    static constexpr int velX = 5;

    float posX = 0.f;
    float posY = 0.f;
    int width = 0;
    int height = 0;
    Color color = BLACK;

    float velY = 0.f;
    bool isJumping = false;
    
    void jump()
    {
        if (!isJumping) 
        {
            velY = jumpForce;
            isJumping = true;
        }
    }

    void update()
    {
        posY += velY;
        velY += gravity;
    }

    constexpr void draw() const
    {
        DrawRectangle(static_cast<int>(posX), static_cast<int>(posY), width, height, color);
    }

    void move(int x, int y)
    {
        posX += x * velX;
        posY += y * velY;
    }
};
