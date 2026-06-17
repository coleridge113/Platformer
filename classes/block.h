#pragma once

#include "raylib.h"

struct Block {
    static constexpr float GRAVITY = 0.4f;
    static constexpr int JUMP_FORCE = -10;

    float x;
    float y;
    int width;
    int height;
    Color color;

    float velocity = 0.f;
    bool isGrounded = false;
    
    void jump()
    {
        if (isGrounded) {
            velocity = JUMP_FORCE;
            isGrounded = false;
        }
    }

    void update()
    {
        y += velocity;
        velocity += GRAVITY;

        if (y >= 620 - height) {
            y = 620 - height;
            velocity = 0;
            isGrounded = true;
        } else {
            isGrounded = false;
        }
    }

    void draw()
    {
        DrawRectangle(static_cast<int>(x), static_cast<int>(y), width, height, color);
    }
};
