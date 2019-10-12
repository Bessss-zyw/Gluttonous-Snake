
#include "snakenode.h"

SnakeNode::SnakeNode()
{
    posX = 0;
    posY = 0;
    SNode = nullptr;

}

SnakeNode::SnakeNode(int posx,int posy)
{
    posX = posx;
    posY = posy;
    SNode = nullptr;
}

SnakeNode::SnakeNode(int posx,int posy,SnakeNode *node)
{
    posX = posx;
    posY = posy;
    SNode = node;
}

SnakeNode::~SnakeNode()
{
    if (SNode != nullptr) delete SNode;
}




int SnakeNode::POSX()
{
    return posX;
}

int  SnakeNode::POSY()
{
    return posY;
}

SnakeNode  *SnakeNode::SNODE()
{
    return SNode;
}




void SnakeNode::changePosX(int posx)
{
    posX = posx;
}

void SnakeNode::changePosY(int posy)
{
    posY = posy;
}

void SnakeNode::changeNode(SnakeNode *node)
{
    SNode = node;
}




void up(SnakeNode *shead)
{
    if (shead->SNODE() != nullptr && shead->SNODE()->POSY() == shead->POSY()-10) return;

    SnakeNode *newhead = shead;
    int pox = shead->POSX(),poy = shead->POSY(),temp;

    while(newhead->SNODE() != nullptr)
    {
        temp = pox; pox = newhead->SNODE()->POSX(); newhead->SNODE()->changePosX(temp);
        temp = poy; poy = newhead->SNODE()->POSX(); newhead->SNODE()->changePosY(temp);
        newhead = newhead->SNODE();
    }
    shead->changePosY(shead->POSY()-10);
}

void down(SnakeNode *shead)
{
    if (shead->SNODE() != nullptr && shead->SNODE()->POSY() == shead->POSY()+10) return;

    SnakeNode *newhead = shead;
    int pox = shead->POSX(),poy = shead->POSY(),temp;


    while(newhead->SNODE() != nullptr)
    {
        temp = pox; pox = newhead->SNODE()->POSX(); newhead->SNODE()->changePosX(temp);
        temp = poy; poy = newhead->SNODE()->POSX(); newhead->SNODE()->changePosY(temp);
        newhead = newhead->SNODE();
    }
    shead->changePosY(shead->POSY()+10);
}

void left(SnakeNode *shead)
{
    if (shead->SNODE() != nullptr && shead->SNODE()->POSX() == shead->POSX()-10) return;

    SnakeNode *newhead = shead;
    int pox = shead->POSX(),poy = shead->POSY(),temp;


    while(newhead->SNODE() != nullptr)
    {
        temp = pox; pox = newhead->SNODE()->POSX(); newhead->SNODE()->changePosX(temp);
        temp = poy; poy = newhead->SNODE()->POSX(); newhead->SNODE()->changePosY(temp);
        newhead = newhead->SNODE();
    }
    shead->changePosX(shead->POSX()-10);
}

void right(SnakeNode *shead)
{
    if (shead->SNODE() != nullptr && shead->SNODE()->POSX() == shead->POSX()+10) return;

    SnakeNode *newhead = shead;
    int pox = shead->POSX(),poy = shead->POSY(),temp;


    while(newhead->SNODE() != nullptr)
    {
        temp = pox; pox = newhead->SNODE()->POSX(); newhead->SNODE()->changePosX(temp);
        temp = poy; poy = newhead->SNODE()->POSX(); newhead->SNODE()->changePosY(temp);
        newhead = newhead->SNODE();
    }
    shead->changePosX(shead->POSX()+10);
}
