#ifndef SNAKEMAINWINDOW_H
#define SNAKEMAINWINDOW_H

#include <QMainWindow>
#include "gamewindow.h"

namespace Ui {
class SnakeMainWindow;
}

class SnakeMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SnakeMainWindow(QWidget *parent = nullptr);
    ~SnakeMainWindow();


private slots:
    void btn_play_clicked();
    void btn_leave_clicked();

private:
    Ui::SnakeMainWindow *ui;
    GameWindow play;
};

#endif // SNAKEMAINWINDOW_H
