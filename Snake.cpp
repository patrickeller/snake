#include <string>
#include <algorithm>

#include "config.cpp"

#include "Snake.hpp"
#include "Position.hpp"




void Snake::debug()
{
    //std::cout << "direction:" << std::endl;
    //std::cout << "\tx:" << this->directionX << std::endl;
    //std::cout << "\ty:" << this->directionY << std::endl;
    //std::cout << "------" << std::endl;
    //std::cout << "snack:" << std::endl;
    //std::cout << "\tx:" << this->snack.x << std::endl;
    //std::cout << "\ty:" << this->snack.y << std::endl;
    //std::cout << "------" << std::endl;
    // std::cout << "History:" << std::endl;
    // for (Position c : this->history)
    //{
    //     std::cout << "\tx:" << c.x << std::endl;
    //     std::cout << "\ty:" << c.y << std::endl;
    //     std::cout << "\t------" << std::endl;
    //}
}

Position Snake::generateSnack()
{
    Position snack = Position(
        (rand() % (ARENA_WIDTH - 1)) + 1,
        (rand() % (ARENA_HEIGHT - 1)) + 1);

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
    std::sort(snakePos.begin(), snakePos.end(), [](Position lsp, Position rsp)
              { return lsp.getUID() < rsp.getUID(); });

    for (int i = 0; i < snakePos.size() - 1; i++)
    {
        if (snakePos[i].x == snakePos[i + 1].x && snakePos[i].y == snakePos[i + 1].y)
            return true;
    }

    return false;
}

bool Snake::isBorderCrash()
{
    Position head = this->history.back();

    if (head.x == 1 || head.y == 1 || head.x == ARENA_WIDTH || head.y == ARENA_HEIGHT)
        return true;

    return false;
}

bool Snake::isSnackCrash()
{
    Position head = this->history.back();

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
    this->history.push_back(Position(this->history.back().x + this->directionX, this->history.back().y + this->directionY));
    if (isSnackCrash())
    {
        this->snack = generateSnack();
    }
    else
    {
        this->history.erase(this->history.begin());
    }
    if (isSelfCrash() || isBorderCrash())
    {
        return false;
    }
    return true;
}