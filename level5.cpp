#include "level5.h"
#include "ui_level5.h"
#include "ventana.h"
#include "ui_ventana.h"
#include <QDebug>
#include <QFont>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

Level5::Level5(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Level5)
{
    ui->setupUi(this);
    setGeometry(0,30,1366,700);
    setMinimumSize(1366,700);
    setMaximumSize(1366,700);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Images/level5.jpg")));
    scene=new QGraphicsScene();
    scene->setSceneRect(0,0,1366,700);
    ui->graphicsView->setScene(scene);

    ave.append(new Capucho(1));
    ave.last()->setPos(140,450);
    ave.last()->setScale(1.2);
    scene->addItem(ave.last());

    int y1=-100;
    for(int i=0; i<10;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(400,y1);
        y1-=40;
        scene->addItem(caja.last());
        }

    int y2=-400;
    for(int i=0; i<11;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(500,y2);
        y2-=40;
        scene->addItem(caja.last());
        }

    int y3=-800;
    for(int i=0; i<12;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(600,y3);
        y3-=40;
        scene->addItem(caja.last());
        }

    int y4=400;
    for(int i=0; i<1;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(800,y4);
        scene->addItem(caja.last());
        }
    cerdo.append(new Esmad(1));
    cerdo.last()->setPos(800,363);
    scene->addItem(cerdo.last());

    int y5=200;
    for(int i=0; i<1;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(900,y5);
        scene->addItem(caja.last());
        }
    cerdo.append(new Esmad(1));
    cerdo.last()->setPos(900,163);
    scene->addItem(cerdo.last());

    int y6=350;
    for(int i=0; i<1;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(1000,y6);
        scene->addItem(caja.last());
        }
    cerdo.append(new Esmad(1));
    cerdo.last()->setPos(1000,313);
    scene->addItem(cerdo.last());

    int y7=540;
    for(int i=0; i<1;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(1100,y7);
        scene->addItem(caja.last());
        }
    cerdo.append(new Esmad(1));
    cerdo.last()->setPos(1100,503);
    scene->addItem(cerdo.last());

    int y8=80;
    for(int i=0; i<1;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(1200,y8);
        scene->addItem(caja.last());
        }
    cerdo.append(new Esmad(1));
    cerdo.last()->setPos(1200,43);
    scene->addItem(cerdo.last());

    int y9=100;
    for(int i=0; i<1;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(700,y9);
        scene->addItem(caja.last());
        }
    cerdo.append(new Esmad(1));
    cerdo.last()->setPos(700,63);
    scene->addItem(cerdo.last());

    score= new Score;
    scene->addItem(score);


    timer=new QTimer();
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    connect(timer,SIGNAL(timeout()),this,SLOT(agregar()));
    timer->start(3);

}

Level5::~Level5()
{
    delete ui;
}
void Level5::on_pushButton_clicked()
{
    timer->stop();
    scene->clear();
    close();
    ventana *v =new ventana;
    v->show();
}
void Level5::agregar()
{

    if(ave.last()->x()>=160 || ave.last()->y()>=600 || ave.last()->x()<0 ){
        ave.append(new Capucho(1));
        ave.last()->setPos(140,450);
        ave.last()->setScale(1.2);
        scene->addItem(ave.last());
        score->increase();
        contpajaros-=1;
    }
    if (contpajaros == -1){
        timer->stop();
        opciones = new Options5;
        opciones->show();
        scene->clear();
        close();
    }

}
