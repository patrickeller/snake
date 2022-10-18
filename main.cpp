//#include <conio.h> //sleep
//
//#include <iostream> //console
//
//#include <vector>
//#include <string>
//#include <chrono> //time
//
//#include <algorithm>
//
//#include <windows.h>
//#include <cwchar>
//
//
//#include <wx/wx.h>
//
//
//#define KEY_UP 72
//#define KEY_LEFT 75
//#define KEY_RIGHT 77
//#define KEY_DOWN 80
//
//#define ARENA_WIDTH 32
//#define ARENA_HEIGHT 20
//
//
////______________________
//
////#include "./drawer.cpp"
//
////______________________
//
//
//
//class Cords
//{
//
//public:
//    unsigned int x, y;
//
//public:
//    Cords(int x, int y)
//    {
//        this->x = x;
//        this->y = y;
//    }
//
//public:
//    std::string getUID()
//    {
//        return std::to_string(this->x) + "_" + std::to_string(this->y);
//    }
//};
//
//class Snake
//{
//
//public:
//    short signed int directionX = 1;
//
//public:
//    short signed int directionY = 0;
//
//public:
//    Cords snack = Cords(0, 0);
//
//public:
//    std::vector<Cords>
//        history = {
//            Cords(5, 4),
//            Cords(6, 4),
//            Cords(7, 4),
//    };
//
//public:
//    void debug()
//    {
//        std::cout << "direction:" << std::endl;
//        std::cout << "\tx:" << this->directionX << std::endl;
//        std::cout << "\ty:" << this->directionY << std::endl;
//        std::cout << "------" << std::endl;
//        std::cout << "snack:" << std::endl;
//        std::cout << "\tx:" << this->snack.x << std::endl;
//        std::cout << "\ty:" << this->snack.y << std::endl;
//        std::cout << "------" << std::endl;
//        // std::cout << "History:" << std::endl;
//        // for (Cords c : this->history)
//        //{
//        //     std::cout << "\tx:" << c.x << std::endl;
//        //     std::cout << "\ty:" << c.y << std::endl;
//        //     std::cout << "\t------" << std::endl;
//        // }
//    }
//};
//
//Cords generateSnack(Snake snake)
//{
//    Cords snack = Cords(
//        (rand() % (ARENA_WIDTH - 1)) + 1,
//        (rand() % (ARENA_HEIGHT - 1)) + 1);
//
//    for (Cords h : snake.history)
//    {
//        if (snack.x == h.x || snack.y == h.y)
//        {
//            return generateSnack(snake);
//        }
//    }
//    return snack;
//}
//
//char getBorder(int x, int y)
//{
//    if (x == 1 && y == 1)
//        return 201; //╔
//    if (x == ARENA_WIDTH && y == ARENA_HEIGHT)
//        return 188; //╝
//    if (x == ARENA_WIDTH && y == 1)
//        return 187; //╗
//    if (x == 1 && y == ARENA_HEIGHT)
//        return 200; //╚
//    if (x == 1 || x == ARENA_WIDTH)
//        return 186; //║
//    if (y == 1 || y == ARENA_HEIGHT)
//        return 205; //═
//    return 32;
//}
//
//bool isSelfCrash(Snake snake)
//{
//    std::vector<Cords> snakePos = snake.history;
//    std::sort(snakePos.begin(), snakePos.end(), [](Cords lsp, Cords rsp)
//              { return lsp.getUID() < rsp.getUID(); });
//
//    for (int i = 0; i < snakePos.size() - 1; i++)
//    {
//        if (snakePos[i].x == snakePos[i + 1].x && snakePos[i].y == snakePos[i + 1].y)
//            return true;
//    }
//
//    return false;
//}
//
//bool isBorderCrash(Snake snake)
//{
//    Cords head = snake.history.back();
//
//    if (head.x == 1 || head.y == 1 || head.x == ARENA_WIDTH || head.y == ARENA_HEIGHT)
//        return true;
//
//    return false;
//}
//
//bool isSnackCrash(Snake snake)
//{
//    Cords head = snake.history.back();
//
//    if (head.x == snake.snack.x && head.y == snake.snack.y)
//    {
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//
//bool moveSnake(Snake *snake)
//{
//    snake->history.push_back(Cords(snake->history.back().x + snake->directionX, snake->history.back().y + snake->directionY));
//    if (isSnackCrash(*snake))
//    {
//        snake->snack = generateSnack(*snake);
//    }
//    else
//    {
//        snake->history.erase(snake->history.begin());
//    }
//    if (isSelfCrash(*snake) || isBorderCrash(*snake))
//    {
//        return false;
//    }
//    return true;
//}
//
//bool isSnakePixel(int x, int y, Snake snake)
//{
//    for (Cords c : snake.history)
//    {
//        if (x == c.x && y == c.y)
//            return true;
//    }
//    return false;
//}
//
//void drawArena(Snake snake)
//{
//    char arena[(ARENA_HEIGHT * ARENA_WIDTH) + ARENA_HEIGHT];
//    unsigned int arenaIndex = 0;
//    for (int y = 1; y <= ARENA_HEIGHT; ++y)
//    {
//        for (int x = 1; x <= ARENA_WIDTH; ++x)
//        {
//            char border = getBorder(x, y);
//            if (border != 32)
//            {
//                arena[arenaIndex] = border;
//            }
//            else if (isSnakePixel(x, y, snake))
//            {
//                arena[arenaIndex] = char(35);
//            }
//            else if (snake.snack.x == x && snake.snack.y == y)
//            {
//                arena[arenaIndex] = char(43);
//            }
//            else
//            {
//                arena[arenaIndex] = char(32);
//            }
//            arenaIndex++;
//        }
//        arena[arenaIndex] = char(10);
//        arenaIndex++;
//    }
//
//    std::cout << arena << std::flush;
//}
//
//void handleInput(Snake *snake)
//{
//    int c = 0;
//
//    int xOffset = snake->history.end()[-1].x - snake->history.end()[-2].x;
//    int yOffset = snake->history.end()[-1].y - snake->history.end()[-2].y;
//
//    switch ((c = _getch()))
//    {
//    case KEY_UP:
//        if (yOffset != 1)
//        {
//            snake->directionY = -1;
//            snake->directionX = 0;
//        }
//        break;
//    case KEY_DOWN:
//        if (yOffset != -1)
//        {
//            snake->directionY = 1;
//            snake->directionX = 0;
//        }
//        break;
//    case KEY_LEFT:
//        if (xOffset != 1)
//        {
//            snake->directionX = -1;
//            snake->directionY = 0;
//        }
//        break;
//    case KEY_RIGHT:
//        if (xOffset != -1)
//        {
//            snake->directionX = 1;
//            snake->directionY = 0;
//        }
//        break;
//    }
//}
//
//unsigned long long int getTime()
//{
//    return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
//}
//
//void consoleInit()
//{
//    HANDLE Hout = ::GetStdHandle(STD_OUTPUT_HANDLE);
//    CONSOLE_FONT_INFOEX Font = {sizeof(Font)};
//    ::GetCurrentConsoleFontEx(Hout, FALSE, &Font);
//    Font.dwFontSize={28,28};
//    SetCurrentConsoleFontEx(Hout,0,&Font);
//
//    HWND hWnd = GetConsoleWindow();
//    ShowWindow(hWnd, SW_SHOWMAXIMIZED);
//}
//
//    
//int main()
//{
//
//    consoleInit();
//
//    Snake snake;
//    snake.snack = generateSnack(snake);
//
//    unsigned int gameTick = 100;
//
//    unsigned long long int lastTime, thisTime;
//    lastTime = getTime();
//
//    bool running = true;
//
//    while (running)
//    {
//        if (_kbhit())
//        {
//            handleInput(&snake);
//        }
//        thisTime = getTime();
//        if (thisTime > lastTime + gameTick)
//        {
//            lastTime = thisTime;
//
//            if (!moveSnake(&snake))
//                break;
//
//            system("cls");
//
//            drawArena(snake);
//            std::cout << "Punktzahl: " << snake.history.size() - 3<<std::endl;
//
//            //snake.debug();
//        }
//    }
//
//
//    std::string exit;
//    std::cout << "GAME OVER!!!";
//    std::getline(std::cin, exit);
//
//    main();
//
//    return 0;
//}