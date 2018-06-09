#include "options.h"
#include "ui_options.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "level1.h"
#include "ui_level1.h"
#include "level2.h"
#include "ui_level2.h"


Options::Options(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options)
{
    ui->setupUi(this);
}

Options::~Options()
{
    delete ui;
}

void Options::on_pushButton_clicked()
{
    close();
    Level2 * siguiente;
    siguiente = new Level2;
    siguiente->show();
}

void Options::on_pushButton_3_clicked()
{
    close();
    Level1 * reintentar;
    reintentar = new Level1;
    reintentar->show();
}

void Options::on_pushButton_2_clicked()
{
    close();
    salir= new MainWindow;
    salir->show();


}
