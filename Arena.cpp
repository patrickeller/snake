#include "config.cpp"

#include "Arena.hpp"
#include "Snake.hpp"
#include "Position.hpp"

char Arena::getBorder(int x, int y)
{
    if (x == 1 && y == 1)
        return 201; //╔
    if (x == ARENA_WIDTH && y == ARENA_HEIGHT)
        return 188; //╝
    if (x == ARENA_WIDTH && y == 1)
        return 187; //╗
    if (x == 1 && y == ARENA_HEIGHT)
        return 200; //╚
    if (x == 1 || x == ARENA_WIDTH)
        return 186; //║
    if (y == 1 || y == ARENA_HEIGHT)
        return 205; //═
    return 32;
}

bool Arena::isSnakePixel(int x, int y, Snake snake)
{
    for (Position c : snake.history)
    {
        if (x == c.x && y == c.y)
            return true;
    }
    return false;
}

void Arena::drawArena(Snake snake)
{
    char arena[(ARENA_HEIGHT * ARENA_WIDTH) + ARENA_HEIGHT];
    unsigned int arenaIndex = 0;
    for (int y = 1; y <= ARENA_HEIGHT; ++y)
    {
        for (int x = 1; x <= ARENA_WIDTH; ++x)
        {
            char border = getBorder(x, y);
            if (border != 32)
            {
                arena[arenaIndex] = border;
            }
            else if (isSnakePixel(x, y, snake))
            {
                arena[arenaIndex] = char(35);
            }
            else if (snake.snack.x == x && snake.snack.y == y)
            {
                arena[arenaIndex] = char(43);
            }
            else
            {
                arena[arenaIndex] = char(32);
            }
            arenaIndex++;
        }
        arena[arenaIndex] = char(10);
        arenaIndex++;
    }

    // std::cout << arena << std::flush;
}