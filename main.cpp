#include <conio.h> //sleep

#include <iostream> //console
#include <vector>
#include <string>
#include <chrono> //time

//#include <limits>

#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_DOWN 80

// using namespace std;

class Cords
{

public:
    unsigned int x, y;

public:
    Cords(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

class Snake
{

public:
    short signed int directionX = 1;

public:
    short signed int directionY = 0;

public:
    std::vector<Cords> history = {
        Cords(5, 4),
        Cords(6, 4),
        Cords(7, 4),
    };

public:
    void debug()
    {
        std::cout << "direction:" << std::endl;
        std::cout << "\tx:" << directionX << std::endl;
        std::cout << "\ty:" << directionY << std::endl;
        std::cout << "History:" << std::endl;
        for (Cords c : history)
        {
            std::cout << "\tx:" << c.x << std::endl;
            std::cout << "\ty:" << c.y << std::endl;
            std::cout << "\t------" << std::endl;
        }
    }
};

char getBorder(int x, int y, int width, int height)
{
    if (x == 0 && y == 0)
        return 201; //╔
    if (x == width - 1 && y == height - 1)
        return 188; //╝
    if (x == width - 1 && y == 0)
        return 187; //╗
    if (x == 0 && y == height - 1)
        return 200; //╚
    if (x == 0 || x == width - 1)
        return 186; //║
    if (y == 0 || y == height - 1)
        return 205; //═
    return 32;
}

void moveSnake(Snake *snake)
{
    snake->history.erase(snake->history.begin());
    snake->history.push_back(Cords(
        snake->history.back().x + snake->directionX,
        snake->history.back().y + snake->directionY));
}

bool isSnake(int x, int y, Snake snake)
{
    for (Cords c : snake.history)
    {
        if (x == c.x && y == c.y)
            return true;
    }
    return false;
}

void drawArena(int height, int width, Snake snake)
{
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            char border = getBorder(x, y, width, height);
            if (border != 32)
            {
                std::cout << border;
            }
            else if (isSnake(x, y, snake))
            {
                std::cout << char(169);
            }
            else
            {
                std::cout << char(32);
            }
        }
        std::cout << std::endl;
    }
}

void handleInput(Snake *snake)
{
    int c = 0;
    switch ((c = getch()))
    {
    case KEY_UP:
        snake->directionY = -1;
        snake->directionX = 0;
        break;
    case KEY_DOWN:
        snake->directionY = 1;
        snake->directionX = 0;
        break;
    case KEY_LEFT:
        snake->directionX = -1;
        snake->directionY = 0;
        break;
    case KEY_RIGHT:
        snake->directionX = 1;
        snake->directionY = 0;
        break;
    }
}

unsigned long long int getTime()
{
    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

int main()
{

    Snake snake;
    unsigned int gameTick = 500;

    unsigned long long int lastTime, thisTime;
    lastTime = getTime();

    while (true)
    {
        if (kbhit())
        {
            handleInput(&snake);
        }
        thisTime = getTime();
        if (thisTime > lastTime + gameTick)
        {
            lastTime = thisTime;

            moveSnake(&snake);
            // printf("\033c");
            drawArena(16, 64, snake);
            snake.debug();
        }
    }

    return 0;
}