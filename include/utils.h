#pragma once

#include <random>

inline int generateRandom(int a, int b)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(a, b);

    return distr(gen);
}
