#include "multiplayer.h"
#include "ui_multiplayer.h"
#include <QDebug>

multiplayer::multiplayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::multiplayer)
{
    //create a data base in sqlite

    ui->setupUi(this);
    QString nombre;
    nombre="BaseDeDatos.sqlite";
    dbmain=QSqlDatabase::addDatabase("QSQLITE");
    dbmain.setDatabaseName(nombre);
    if (dbmain.open()){
        qDebug()<<"Base De Datos Creada";
    }
    else{
        qDebug()<<"Error";
    }
}

multiplayer::~multiplayer()
{
    delete ui;
}

void multiplayer::on_pushButton_clicked()
{
    registro *Registro = new registro(0);
    Registro->show();
}

void multiplayer::on_pushButton_2_clicked()
{
    login *Login = new login(0);
    Login->show();
}
