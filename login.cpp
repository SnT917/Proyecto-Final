#include "login.h"
#include "ui_login.h"
#include <QMessageBox>
#include <QDebug>
#include "multi.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_commandLinkButton_clicked()
{
    QString nick=ui->Nick->text();
    QString contra=ui->Contra->text();
    QSqlQuery buscar;
    QString pass2;
    QString Consulta;
    QString nombre;
    Consulta.append("SELECT * FROM usuario where nick='"+nick+"'");
    buscar.prepare(Consulta);
    if (buscar.exec()){

        qDebug()<<"Consulta Realizada";
        while (buscar.next()){

            pass2=buscar.value(1).toByteArray().constData();
            nombre=buscar.value(0).toByteArray().constData();
            qDebug()<<pass2;
            qDebug()<<nombre;
        }
    }
    else{
        qDebug()<<"Error De Consulta";
        QMessageBox::critical(this,tr("ERROR"),tr("El Usuario No Existe"));
    }
    if (pass2==contra){
        QMessageBox::information(this,tr("Bienvenido"),tr("Bienvenido %1").arg(nombre));
        close();

        Multi= new multi;
        Multi->show();
    }
    else{
        QMessageBox::critical(this,tr("ERROR"),tr("Contraseña Incorrecta"));

    }


}
