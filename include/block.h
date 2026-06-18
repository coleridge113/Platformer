#pragma once

#include "raylib.h"
#include "constants.h"

struct Block 
{
    static constexpr int jumpForce = -10;

    float x = 0.f;
    float y = 0.f;
    int width = 0;
    int height = 0;
    Color color = BLACK;

    float velocity = 0.f;
    bool isJumping = false;
    
    void jump()
    {
        if (isJumping) 
        {
            velocity = jumpForce;
            isJumping = true;
        }
    }

    void update()
    {
        y += velocity;
        velocity += gravity;

        if (y >= windowHeight - 10)
        {
            velocity = 0;
            isJumping = false;
        }
        else
        {
            isJumping = true;
        }
    }

    void draw()
    {
        DrawRectangle(static_cast<int>(x), static_cast<int>(y), width, height, color);
    }
};
