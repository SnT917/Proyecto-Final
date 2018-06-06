#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "multiplayer.h"
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    N = new ventana();
    login = new multiplayer;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    N->show();
    close();
}

void MainWindow::on_pushButton_2_clicked()
{

}

void MainWindow::on_pushButton_3_clicked()
{
    login->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    close();
}
