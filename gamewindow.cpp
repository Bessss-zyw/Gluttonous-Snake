#include "gamewindow.h"
#include "ui_gamewindow.h"

GameWindow::GameWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameWindow)
{
    ui->setupUi(this);
    head = new SnakeNode(280,200);
    head = new SnakeNode(290,200,head);
    head = new SnakeNode(300,200,head);
}

GameWindow::~GameWindow()
{
    delete ui;

    if (head == nullptr) return;
    SnakeNode *temp = head->SNODE();
    while(temp != nullptr){
        if (head != nullptr) delete head;
        head = temp;
        temp = temp->SNODE();
    }
    if(head != nullptr) delete head;
}

void GameWindow::paintEvent(QPaintEvent*)
{
    //游戏背景
    QPainter painter(this);
    QRect rect_0(80,50,400,300);
    painter.fillRect(rect_0,QColor(255,255,255));

    //蛇
    SnakeNode *temp = head;
    while(temp!=nullptr){
        QRect snake(temp->POSX(),temp->POSY(),10,10);
        painter.fillRect(snake,QColor(0,0,0));
        temp = temp->SNODE();
    }
}

void GameWindow::keyPressEvent(QKeyEvent *event)
{
    //键盘控制
    switch (event->key()) {
    case Qt::Key_Up:
        up(head);break;
    case Qt::Key_Down:
        down(head);break;
    case Qt::Key_Left:
        left(head);break;
    case Qt::Key_Right:
        right(head);break;
    }


    //判断蛇是否跑出游戏背景
    if(head->POSX() <= 80 || head->POSX() >= 480 || head->POSY() <= 50 || head->POSY() >= 350)
    {
        qDebug() << "YOU ARE DEAD.";
        this->close();
    }else {
        repaint();
        QWidget::keyPressEvent(event);
    }
}
