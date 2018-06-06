#include "ventana.h"
#include "ui_ventana.h"
#include "mainwindow.h"             //Se llama la libreria dentro de ventana.cpp
#include "level1.h"
#include "level2.h"
#include "level3.h"
#include "level4.h"
#include "level5.h"

ventana::ventana(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ventana)
{
    ui->setupUi(this);
}

ventana::~ventana()
{
    delete ui;
}


void ventana::on_pushButton_2_clicked()
{
     MainWindow *M =new MainWindow;       //Se Crea la variable MainWindow dentro de la función, siendo así una variable local
     M->show();                        //Se muestra el MainWindow
     close();                          //Se cierra la ventana que está abierta
}

void ventana::on_pushButton_3_clicked()
{
    Level1 *l1 =new Level1;
    l1->show();
    close();
}

void ventana::on_pushButton_clicked()
{
    Level2 *l2 =new Level2;
    l2->show();
    close();
}

void ventana::on_pushButton_4_clicked()
{
    Level4 *l4 =new Level4;
    l4->show();
    close();
}

void ventana::on_pushButton_5_clicked()
{
    Level5 *l5 =new Level5;
    l5->show();
    close();
}

void ventana::on_pushButton_6_clicked()
{
    Level3 *l3 =new Level3;
    l3->show();
    close();
}
