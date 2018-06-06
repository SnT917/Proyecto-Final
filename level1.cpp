#include "level1.h"
#include "ui_level1.h"
#include "ventana.h"
#include "ui_ventana.h"
#include <QDebug>
#include <QFont>
#include "Score.h"

Level1::Level1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Level1)
{
    ui->setupUi(this);
    setGeometry(0,30,1366,700);  //set the geometry of the windows
    setMinimumSize(1366,700);
    setMaximumSize(1366,700);

    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Images/level1.jpg")));  //set the background
    scene=new QGraphicsScene();
    scene->setSceneRect(0,0,1366,700);
    ui->graphicsView->setScene(scene);   //create and put the scene

    ave.append(new Capucho(1));          //create the frist capucho
    ave.last()->setPos(140,450);
    ave.last()->setScale(1.2);
    scene->addItem(ave.last());

    //level design

    int y1=1000;
    for(int i=0; i<10;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(y1,-10);
        y1-=42;
        scene->addItem(caja.last());
        }

    int y3=960;
    for(int i=0; i<8;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(y3,-1000);
        y3-=42;
        scene->addItem(caja.last());
        }

    int y4=920;
    for(int i=0; i<6;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(y4,-2000);
        y4-=42;
        scene->addItem(caja.last());
        }

    int y5=880;
    for(int i=0; i<4;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(y5,-3000);
        y5-=42;
        scene->addItem(caja.last());
        }

    int y6=840;
    for(int i=0; i<2;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(y6,-4000);
        y6-=42;
        scene->addItem(caja.last());
        }

    int y7=820;
    for(int i=0; i<1;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(y7,-5000);
        y7-=42;
        scene->addItem(caja.last());
        }

    cerdo.append(new Esmad(1));
    cerdo.last()->setPos(820,-6000);
    scene->addItem(cerdo.last());

    timer=new QTimer();    //Create the timer
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    connect(timer,SIGNAL(timeout()),this,SLOT(agregar()));
    timer->start(0.1);

}

Level1::~Level1()
{
    delete ui;
}

void Level1::on_pushButton_clicked() //push button "volver"
{
    ventana *v =new ventana;
    v->show();
    close();
}
void Level1::agregar()
{
//list of capuchos. In case of launching one, a new one appears
    if(ave.last()->x()>=160 || ave.last()->y()>=600 || ave.last()->x()<0 ){
        ave.append(new Capucho(1));
        ave.last()->setPos(140,450);
        ave.last()->setScale(1.2);
        scene->addItem(ave.last());
    }

}
