#include <string>

#include "Position.hpp"

Position::Position(int x, int y)
{
    this->x = x;
    this->y = y;
}

std::string Position::getUID()
{
    return std::to_string(this->x) + "_" + std::to_string(this->y);
}