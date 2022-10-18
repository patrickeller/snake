#pragma once
#include <vector>

#include "Position.hpp"

class Snake
{

public:
    short signed int directionX = 1;
    short signed int directionY = 0;
    Position snack = Position(0, 0);
    std::vector<Position> history = {
            Position(5, 4),
            Position(6, 4),
            Position(7, 4),
    }; 
    void debug();
};