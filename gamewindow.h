#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>
#include "snakenode.h"

namespace Ui {
class GameWindow;
}

class GameWindow : public QWidget
{
    Q_OBJECT

protected:
    void paintEvent(QPaintEvent*);
    void keyPressEvent(QKeyEvent *event);

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private:
    Ui::GameWindow *ui;
    SnakeNode *head;
};

#endif // GAMEWINDOW_H
