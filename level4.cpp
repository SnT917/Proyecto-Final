#include "level4.h"
#include "ui_level4.h"
#include "ventana.h"
#include "ui_ventana.h"
#include <QDebug>
#include <QFont>

Level4::Level4(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Level4)
{
    ui->setupUi(this);
    setGeometry(0,30,1366,700);
    setMinimumSize(1366,700);
    setMaximumSize(1366,700);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Images/level4.jpg")));
    scene=new QGraphicsScene();
    scene->setSceneRect(0,0,1366,700);
    ui->graphicsView->setScene(scene);


    ave.append(new Capucho(1));
    ave.last()->setPos(140,450);
    ave.last()->setScale(1.2);
    scene->addItem(ave.last());

    int y1=300;
    for(int i=0; i<1;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(800,y1);
        scene->addItem(caja.last());
        }
    cerdo.append(new Esmad(1));
    cerdo.last()->setPos(800,263);
    scene->addItem(cerdo.last());

    int y2=100;
    for(int i=0; i<1;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(1000,y2);
        scene->addItem(caja.last());
        }
    cerdo.append(new Esmad(1));
    cerdo.last()->setPos(1000,63);
    scene->addItem(cerdo.last());

    int y3=500;
    for(int i=0; i<1;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(1200,y3);
        scene->addItem(caja.last());
        }
    cerdo.append(new Esmad(1));
    cerdo.last()->setPos(1200,463);
    scene->addItem(cerdo.last());

    int y4=400;
    for(int i=0; i<1;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(500,y4);
        scene->addItem(caja.last());
        }
    cerdo.append(new Esmad(1));
    cerdo.last()->setPos(500,363);
    scene->addItem(cerdo.last());

    int y5=40;
    for(int i=0; i<1;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(700,y5);
        scene->addItem(caja.last());
        }
    cerdo.append(new Esmad(1));
    cerdo.last()->setPos(700,3);
    scene->addItem(cerdo.last());

    int y6=200;
    for(int i=0; i<1;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(350,y6);
        scene->addItem(caja.last());
        }
    cerdo.append(new Esmad(1));
    cerdo.last()->setPos(350,163);
    scene->addItem(cerdo.last());

    int y7=500;
    for(int i=0; i<1;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(900,y7);
        scene->addItem(caja.last());
        }
    cerdo.append(new Esmad(1));
    cerdo.last()->setPos(900,463);
    scene->addItem(cerdo.last());

    timer=new QTimer();
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    connect(timer,SIGNAL(timeout()),this,SLOT(agregar()));
    timer->start(2.5);
}

Level4::~Level4()
{
    delete ui;
}
void Level4::on_pushButton_clicked()
{
    ventana *v =new ventana;
    v->show();
    close();
}
void Level4::agregar()
{

    if(ave.last()->x()>=160 || ave.last()->y()>=600 || ave.last()->x()<0 ){
        ave.append(new Capucho(1));
        ave.last()->setPos(140,450);
        ave.last()->setScale(1.2);
        scene->addItem(ave.last());
    }

}
