#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(&this->ptimer,SIGNAL(timeout()),this,SLOT(updateTimeAndDisplay()));

    speed = new int[2]{10,0};
    num_0 = new Snake(100,100);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete [] speed;

    delete num_0;

}

void MainWindow::dead()
{
    ptimer.stop();

    QMessageBox msgBox;
    msgBox.setText("Game over!");
    msgBox.setInformativeText("score:" + QString::number(num_0->currentSize));
    msgBox.addButton("确定",QMessageBox::AcceptRole);
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();

    switch (ret) {
      case QMessageBox::AcceptRole:
          // 确定 was clicked
          this->close();
          break;

      default:
          // should never be reached
          break;
    }
}

void MainWindow::paintEvent(QPaintEvent* event)
{
    //background
    QPainter painter(this);
    painter.fillRect(50,50,500,400,QColor(255,255,255));

    //snake
    for (int i = 0;i <= num_0->currentSize ; ++i)
    {
        painter.setBrush(QColor(0,0,0));
        painter.drawRect(num_0->snake[i][0],num_0->snake[i][1],10,10);
        painter.fillRect(num_0->snake[i][0],num_0->snake[i][1],10,10,QColor(200,255,0));
    }

    //food
    painter.fillRect(num_0->fruit[0],num_0->fruit[1],10,10,QColor(255,100,100));

}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    int temp;

    switch (event->key()) {
    case Qt::Key_Up:
        temp = num_0->move(0,-10);
        if (temp == 0) dead();
        else if (temp == 1) {speed[0] = 0;speed[1] = -10;}
        break;
    case Qt::Key_Down:
        temp = num_0->move(0,10);
        if (temp == 0) dead();
        else if (temp == 1) {speed[0] = 0;speed[1] = 10;}
        break;
    case Qt::Key_Left:
        temp = num_0->move(-10,0);
        if (temp == 0) dead();
        else if (temp == 1) {speed[0] = -10;speed[1] = 0;}
        break;
    case Qt::Key_Right:
        temp = num_0->move(10,0);
        if (temp == 0) dead();
        else if (temp == 1) {speed[0] = 10;speed[1] = 0;}
        break;
    }
    repaint();
    QWidget::keyPressEvent(event);
    this->ui->lcd_score->display(num_0->currentSize);
}


void MainWindow::updateTimeAndDisplay()
{
    this->basetime = this->basetime.addSecs(200);
//    QString temp = this->basetime.toString("hh.mm.ss");
    this->ui->lcd_time->display(0);

    int temp = num_0->move(speed[0],speed[1]);
    if (temp == 0) dead();
    repaint();

}

void MainWindow::on_btn_start_clicked()
{
    this->basetime.setHMS(0,0,0,0);
    this->ptimer.start(200);
}

void MainWindow::on_btn_stop_clicked()
{
    this->ptimer.stop();
    this->m_lock.lock();
}
