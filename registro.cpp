#include "registro.h"
#include "ui_registro.h"
#include <QDebug>
#include <QMessageBox>

registro::registro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::registro)
{
    ui->setupUi(this);
    CrearTabla();
}

registro::~registro()
{
    delete ui;
}

void registro::CrearTabla()  //create a table with nombre, pass and nick.
{
    QString consulta;
    consulta.append("CREATE TABLE IF NOT EXISTS usuario("
                    "nombre VARCHAR(25),"
                    "pass VARCHAR(25),"
                    "nick VARCHAR(25) PRIMARY KEY "
                    ");");
    QSqlQuery crear;
    crear.prepare(consulta);
    if (crear.exec()){
        qDebug()<<"Tabla Creada";

    }
    else{
        qDebug()<<"Tabla No Creada"<<crear.lastError();   //error handling
    }


}
void registro::on_pushButton_clicked()
{
    QString user=ui->Usuario->text();
    QString contra=ui->Contra->text();
    QString nick=ui->Nick->text();
    qDebug()<<user;
    qDebug()<<contra;
    qDebug()<<nick;
    QSqlQuery insertar_db;
    insertar_db.prepare("INSERT INTO usuario(nombre,pass,nick)"
                        "VALUES(:nombre,:pass,:nick)");
    insertar_db.bindValue(":nombre",user);
    insertar_db.bindValue(":pass",contra);
    insertar_db.bindValue(":nick",nick);

    if(insertar_db.exec()){
        qDebug()<<"Datos ingresados a la tabla";
        QMessageBox::information(this,tr("Exito"),tr("Registro Exitoso"));
    }
    else {
        qDebug()<<"Error al insertar los datos"<<insertar_db.lastError();   //error handling
        QMessageBox::critical(this,tr("ERROR"),tr("El Nickname ya está en uso"));
    }
    close();


}
