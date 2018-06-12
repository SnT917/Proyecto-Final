#include "options5.h"
#include "ui_options5.h"
#include "level5.h"

Options5::Options5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Options5)
{
    ui->setupUi(this);
}

Options5::~Options5()
{
    delete ui;
}

void Options5::on_pushButton_2_clicked()
{
    close();
    Level5 * reintentar;
    reintentar = new Level5;
    reintentar->show();
}

void Options5::on_pushButton_3_clicked()
{
    close();
    salir= new MainWindow;
    salir->show();
}
