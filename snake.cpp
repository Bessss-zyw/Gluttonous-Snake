#include "snake.h"

Snake::Snake()
{
    //蛇的默认初始位置
    snake = new int*[10];
    snake[0] = new int[2];
    snake[0][0] = 0;
    snake[0][1] = 0;

    fruit = food();

    currentSize = 0;
    maxSize = 10;
}

Snake::Snake(int x,int y)
{
    //可以设置蛇的初始位置
    snake = new int*[10];
    snake[0] = new int[2];
    snake[0][0] = x;
    snake[0][1] = y;

    fruit = food();

    currentSize = 0;
    maxSize = 10;
}

Snake::~Snake()
{
    for(int i = 0; i <= currentSize ; ++i){
        delete [] snake[i];
    }
    delete [] snake;

    delete [] fruit;
}

void Snake::doubleSize()
{
    if(currentSize+1 != maxSize)  return;
    int **temp = snake;
    snake = new int*[maxSize*2];

    //复制并释放原有空间
    for(int i = 0 ; i < maxSize ; ++i){
        snake[i] = new int[2];
        snake[i][0] = temp[i][0];
        snake[i][1] = temp[i][1];
        delete [] temp[i];
    }
    delete [] temp;

    maxSize *= 2;
}

int Snake::generateRandomNumber(int min, int max)
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    return qrand() % (max-min+1) + min;
}

bool Snake::judgefood(int x, int y)
{
    for (int i = 0; i <= currentSize; ++i){
        if (x == snake[i][0] && y == snake[i][1]) return false;
    }
    return true;
}

int *Snake::food()
{
        //产生水果 ，判断是否产生在蛇身上
    int *temp = new int[2];
    temp[0] = generateRandomNumber(6,53)*10;
    temp[1] = generateRandomNumber(6,43)*10;

    while(judgefood(temp[0],temp[1]) == false)
    {
        temp[0] = generateRandomNumber(6,53)*10;
        temp[1] = generateRandomNumber(6,43)*10;
    }

    return temp;
}



int Snake::judgeDeadOrNot(int dx, int dy)
{
    //朝后走illegal
    if (currentSize > 0 && snake[currentSize][0]+dx == snake[currentSize-1][0] && snake[currentSize][1] + dy == snake[currentSize-1][1])
        return -1; //illegal

    //撞到自己或 撞墙
    for (int i = 0; i<currentSize-2;++i){
        if (snake[currentSize][0]+dx == snake[i][0] && snake[currentSize][1] + dy == snake[i][1])
            return 0; //dead
    }
    if (snake[currentSize][0]+dx < 50 || snake[currentSize][0]+dx > 540 || snake[currentSize][1]+dy < 50 || snake[currentSize][1]+dy > 440)
        return 0; //dead

    //吃到水果
    if (snake[currentSize][0]+dx == fruit[0] && snake[currentSize][1]+dy == fruit[1]){
        addNode(fruit[0],fruit[1]);
        fruit = food();
    }

    return 1;
}






//dead 0
//continue 1
//illegal -1


int Snake::move(int dx,int dy)
{
    //judge if the move is legal
//    if (currentSize > 0 && snake[currentSize][0]+dx == snake[currentSize-1][0] && snake[currentSize][1] + dy == snake[currentSize-1][1])
//        return; //illegal

//    for (int i = 0; i<currentSize-2;++i){
//        if (snake[currentSize][0]+dx == snake[i][0] && snake[currentSize][1] + dy == snake[i][1])
//            return; //dead
//    }
//    if (snake[currentSize][0]+dx < 0 || snake[currentSize][0]+dx > 600 || snake[currentSize][1]+dy < 0 || snake[currentSize][1]+dy > 500)
//        return; //dead

    int flag = judgeDeadOrNot(dx,dy);
    if (flag == -1) return -1;  //illegeal
    else if (flag == 0) {qDebug() << "YOU ARE DEAD!" << endl; return 0;}

    for (int i = 0;i<currentSize;++i){
        snake[i][0] = snake[i+1][0];
        snake[i][1] = snake[i+1][1];
    }
    snake[currentSize][0] += dx;
    snake[currentSize][1] += dy;

    return 1;
}

void Snake::addNode(int x,int y)
{
    if(++currentSize == maxSize) doubleSize();

    snake[currentSize] = new int[2];
    snake[currentSize][0] = x;
    snake[currentSize][1] = y;
}
