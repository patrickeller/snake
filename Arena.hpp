#pragma once

#include "Snake.hpp"
#include "Position.hpp"

class Arena
{
public:
    static void drawArena(Snake snake);

private:
    static char getBorder(int x, int y);
    static bool isSnakePixel(int x, int y, Snake snake);
};