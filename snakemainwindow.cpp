#include "snakemainwindow.h"
#include "ui_snakemainwindow.h"

SnakeMainWindow::SnakeMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SnakeMainWindow)
{
    ui->setupUi(this);
    connect(this->ui->btn_play,SIGNAL(clicked()),this,SLOT(btn_play_clicked()));
    connect(this->ui->btn_leave,SIGNAL(clicked()),this,SLOT(btn_leave_clicked()));
}

SnakeMainWindow::~SnakeMainWindow()
{
    delete ui;
}

void SnakeMainWindow::btn_play_clicked()
{
    play.show();
}

void SnakeMainWindow::btn_leave_clicked()
{
    this->close();
}
