#pragma once

#include <wx/string.h>

#include "Snake.hpp"
#include "Position.hpp"

class Arena
{
public:
    static std::string drawArenaSymbols(Snake snake);
    static int** getArena(Snake snake);
    enum Type{BLANK, BORDER, SNAKE_LIGHT, SNAKE_DARK, SNACK};

private:
    static char getBorder(int x, int y);
    static signed int getSnakePixel(int x, int y, Snake snake);
};