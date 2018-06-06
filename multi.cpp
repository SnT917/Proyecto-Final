#include "multi.h"
#include "ui_multi.h"
#include <QMessageBox>
#include <QDebug>

multi::multi(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::multi)
{
    ui->setupUi(this);

    scene= new QGraphicsScene (0,0,500,200);
    ui->graphicsView->setScene(scene);

    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Images/multi.png")));

    l1= new QGraphicsLineItem(0,0,500,0);
    l2= new QGraphicsLineItem(0,0,0,200);
    l3= new QGraphicsLineItem(500,0,500,200);
    l4= new QGraphicsLineItem(0,200,500,200);

    scene-> addItem(l1);
    scene-> addItem(l2);
    scene-> addItem(l3);
    scene-> addItem(l4);

    dinosaurio=new objetos(20,160,30,40,":/Images/capucho.png");
    scene->addItem(dinosaurio);

    cactus=new objetos(470,160,25,40,":/Images/esmad.png");
    scene-> addItem(cactus);

    downdino=new objetos(-100,174,45,25,":/Images/capucho.png");
    scene->addItem(downdino);

    timer=new  QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(actualizar()));
    timer->start(20);
}

multi::~multi()
{
    delete ui;
    delete scene;
    delete l1;
    delete l2;
    delete l3;
    delete l4;
    delete dinosaurio;
    delete cactus;
    delete downdino;
    delete timer;
}

void multi::actualizar(){
    setWindowTitle("Capucho's Bomb Adventure Multiplayer");

    puntaje++;
    ui->lcdNumber->display(puntaje/2);

    if(cactus->pos().x() > -500){
        cactus->setPos(cactus->pos().x()-dist,cactus->pos().y());
    }
    else{
        cactus->setPos(0,0);
    }
    if(saltar){
        dinosaurio->setPos(dinosaurio->pos().x(),dinosaurio->pos().y()-10);
    }
    else {
        if(dinosaurio->pos().y()!= 0){
            dinosaurio->setY(dinosaurio->pos().y()+10);
        }
    }
    if(dinosaurio->pos().y() < -80){
        saltar=false;
    }
    if(dinosaurio->collidesWithItem(cactus)){

        timer->stop();

    }

    if(cont==10){
        cont=0;
        dist+=2;
    }
}
void multi::keyPressEvent(QKeyEvent* accion){

    if(accion ->key()== Qt::Key_Space){
        saltar=true;
        cont++;
        cont3++;
    }

}
void multi::keyReleaseEvent(QKeyEvent* accion){
    if(accion->key()==Qt::Key_Enter){

        close();

    }
}
