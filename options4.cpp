#include "options4.h"
#include "ui_options4.h"
#include "level4.h"
#include "level5.h"

Options4::Options4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options4)
{
    ui->setupUi(this);
}

Options4::~Options4()
{
    delete ui;
}

void Options4::on_pushButton_clicked()
{
    close();
    Level5 * siguiente;
    siguiente = new Level5;
    siguiente->show();
}

void Options4::on_pushButton_2_clicked()
{
    close();
    Level4 * reintentar;
    reintentar = new Level4;
    reintentar->show();
}

void Options4::on_pushButton_3_clicked()
{
    close();
    salir= new MainWindow;
    salir->show();
}
