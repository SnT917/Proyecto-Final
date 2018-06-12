#include "options3.h"
#include "ui_options3.h"
#include "level3.h"
#include "level4.h"

Options3::Options3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options3)
{
    ui->setupUi(this);
}

Options3::~Options3()
{
    delete ui;
}

void Options3::on_pushButton_clicked()
{
    close();
    Level4 * siguiente;
    siguiente = new Level4;
    siguiente->show();

}

void Options3::on_pushButton_2_clicked()
{
    close();
    Level3 * reintentar;
    reintentar = new Level3;
    reintentar->show();
}

void Options3::on_pushButton_3_clicked()
{
    close();
    salir= new MainWindow;
    salir->show();
}
