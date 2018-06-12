#include "options2.h"
#include "ui_options2.h"
#include "level3.h"
#include "level2.h"

Options2::Options2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options2)
{
    ui->setupUi(this);
}

Options2::~Options2()
{
    delete ui;
}

void Options2::on_pushButton_clicked()
{
    close();
    Level3 * siguiente;
    siguiente = new Level3;
    siguiente->show();
}
void Options2::on_pushButton_2_clicked()
{
    close();
    Level2 * reintentar;
    reintentar = new Level2;
    reintentar->show();
}

void Options2::on_pushButton_3_clicked()
{
    close();
    salir= new MainWindow;
    salir->show();
}




