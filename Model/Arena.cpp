#include <string>

#include "../config.cpp"

#include "Arena.hpp"
#include "Snake.hpp"
#include "Position.hpp"

char Arena::getBorder(int x, int y)
{
    if (x == 0 && y == 0)
        return 201; //╔
    if (x == ARENA_WIDTH - 1 && y == ARENA_HEIGHT - 1)
        return 188; //╝
    if (x == ARENA_WIDTH - 1 && y == 0)
        return 187; //╗
    if (x == 0 && y == ARENA_HEIGHT - 1)
        return 200; //╚
    if (x == 0 || x == ARENA_WIDTH - 1)
        return 186; //║
    if (y == 0 || y == ARENA_HEIGHT - 1)
        return 205; //═
    return 32;
}

signed int Arena::getSnakePixel(int x, int y, Snake snake)
{
    for (int s = 0; s < snake.history.size(); s++)
    {
        if (x == snake.history[s].x && y == snake.history[s].y)
        {
            if (s % 4 == 0 || s % 4 == 3)
            {
                return SNAKE_LIGHT;
            }
            else
            {
                return SNAKE_DARK;
            }
        }
    }
    return -1;
}

std::string Arena::drawArenaSymbols(Snake snake)
{
    char arena[(ARENA_HEIGHT * ARENA_WIDTH)];
    unsigned int arenaIndex = 0;
    for (int y = 0; y < ARENA_HEIGHT; ++y)
    {
        for (int x = 0; x < ARENA_WIDTH; ++x)
        {
            char border = getBorder(x, y);
            if (border != 32)
            {
                arena[arenaIndex] = border;
            }
            else if (getSnakePixel(x, y, snake) != -1)
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

    // std::cout << arena;

    std::string arenaString = arena;
    return arenaString;
}

int **Arena::getArena(Snake snake)
{
    int **arena = new int *[ARENA_HEIGHT];
    for (int y = 0; y < ARENA_HEIGHT; y++)
    {

        arena[y] = new int[ARENA_WIDTH];

        for (int x = 0; x < ARENA_WIDTH; x++)
        {
            char border = getBorder(x, y);
            signed int snakePixel = getSnakePixel(x, y, snake);

            if (border != 32)
            {
                arena[y][x] = BORDER;
            }
            else if (snakePixel >= 0)
            {
                arena[y][x] = snakePixel;
            }
            else if (snake.snack.x == x && snake.snack.y == y)
            {
                arena[y][x] = SNACK;
            }
            else
            {
                arena[y][x] = BLANK;
            }
        }
    }

    return arena;
}