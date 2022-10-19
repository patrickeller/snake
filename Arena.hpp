#pragma once

#include <wx/string.h>

#include "Snake.hpp"
#include "Position.hpp"

class Arena
{
public:
    static std::string drawArena(Snake snake);

private:
    static char getBorder(int x, int y);
    static bool isSnakePixel(int x, int y, Snake snake);
};