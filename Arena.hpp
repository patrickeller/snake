#pragma once

#include <wx/string.h>

#include "Snake.hpp"
#include "Position.hpp"

class Arena
{
public:
    static std::string drawArenaSymbols(Snake snake);
    static int** getArena(Snake snake);
    enum Type{BLANK, BORDER, SNAKE, SNACK};

private:
    static char getBorder(int x, int y);
    static bool isSnakePixel(int x, int y, Snake snake);
};