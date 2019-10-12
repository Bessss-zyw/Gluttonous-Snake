#ifndef SNAKENODE_H
#define SNAKENODE_H

#include <QtDebug>
#include <QRect>
#include <QColor>
#include <QBrush>
#include <QPainter>
#include <QKeyEvent>

class SnakeNode
{
private:
    int posX,posY;
    SnakeNode *SNode;

public:
    SnakeNode(int posx,int posy,SnakeNode *node);
    SnakeNode(int posx,int posy);
    SnakeNode();
    ~SnakeNode();

    void changePosX(int posx);
    void changePosY(int posy);
    void changeNode(SnakeNode *node);
    int POSX();
    int POSY();
    SnakeNode *SNODE();

};

void up(SnakeNode *shead);
void down(SnakeNode *shead);
void left(SnakeNode *shead);
void right(SnakeNode *shead);

#endif // SNAKENODE_H
