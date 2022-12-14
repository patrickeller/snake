#include <string>
#include <algorithm>

#include "../config.cpp"

#include "Snake.hpp"
#include "Position.hpp"

void Snake::debug()
{
    // std::cout << "direction:" << std::endl;
    // std::cout << "\tx:" << this->directionX << std::endl;
    // std::cout << "\ty:" << this->directionY << std::endl;
    // std::cout << "------" << std::endl;
    // std::cout << "snack:" << std::endl;
    // std::cout << "\tx:" << this->snack.x << std::endl;
    // std::cout << "\ty:" << this->snack.y << std::endl;
    // std::cout << "------" << std::endl;
    //  std::cout << "History:" << std::endl;
    //  for (Position c : this->history)
    //{
    //      std::cout << "\tx:" << c.x << std::endl;
    //      std::cout << "\ty:" << c.y << std::endl;
    //      std::cout << "\t------" << std::endl;
    // }
}

Position Snake::generateSnack()
{
    Position snack = Position(
        (rand() % (ARENA_WIDTH - 2)) + 1,
        (rand() % (ARENA_HEIGHT - 2)) + 1);

    for (Position h : this->history)
    {
        if (snack.x == h.x || snack.y == h.y)
        {
            return generateSnack();
        }
    }
    return snack;
}

bool Snake::isSelfCrash()
{
    std::vector<Position> snakePos = this->history;
    Position head = this->history.front();

    for (int i = 1; i < snakePos.size(); i++)
    {
        if (head.x == snakePos[i].x && head.y == snakePos[i].y)
            return true;
    }

    return false;
}

bool Snake::isBorderCrash()
{
    Position head = this->history.front();

    if (head.x == 0 || head.y == 0 || head.x == ARENA_WIDTH - 1 || head.y == ARENA_HEIGHT - 1)
        return true;

    return false;
}

bool Snake::isSnackCrash()
{
    Position head = this->history.front();

    if (head.x == this->snack.x && head.y == this->snack.y)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Snake::moveSnake()
{
    this->history.insert(this->history.begin(), Position(this->history.front().x + this->directionX, this->history.front().y + this->directionY));
    if (isSnackCrash())
    {
        this->snack = generateSnack();
    }
    else
    {
        this->history.pop_back();
    }
    if (isSelfCrash() || isBorderCrash())
    {
        return false;
    }
    return true;
}