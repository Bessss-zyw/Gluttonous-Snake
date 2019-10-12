#ifndef SNAKE_H
#define SNAKE_H

#include <QRect>
#include <QPainter>
#include <QColor>
#include <QBrush>
#include <QtDebug>
#include <QKeyEvent>
#include <QTime>
#include <QtGlobal>
#include <QString>
#include <QMessageBox>


class Snake
{
private:
    void doubleSize();
    int judgeDeadOrNot(int dx,int dy);


    int generateRandomNumber(int min,int max);
    int *food();
    bool judgefood(int x,int y);


public:
    int **snake;
    int *fruit;
    int currentSize;
    int maxSize;

public:
    Snake();
    Snake(int x,int y);
    ~Snake();
    int move(int dx,int dy);
    void addNode(int x,int y);
};

//class GNSSREPLAY
//{
//private:
//    QMutex m_lock;

//public:
//    void run();
//    void pause();
//    void resume();

//};

#endif // SNAKE_H
