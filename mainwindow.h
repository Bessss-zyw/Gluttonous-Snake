#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "snake.h"
#include <QtGlobal>
#include <QTime>
#include <QTimer>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

protected:
    void paintEvent(QPaintEvent*event);
    void keyPressEvent(QKeyEvent *event);

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() ;

private slots:
    void on_btn_start_clicked();
    void updateTimeAndDisplay();
    void on_btn_stop_clicked();

private:
    Ui::MainWindow *ui;
    Snake *num_0;
    int *speed;
    QTime basetime;
    QTimer ptimer;
    QMutex m_lock;

private:
    void dead();

};



#endif // MAINWINDOW_H
