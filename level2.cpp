#include "level2.h"
#include "ui_level2.h"
#include "ventana.h"
#include "options2.h"
#include "ui_ventana.h"
#include <QDebug>
#include <QFont>

Level2::Level2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Level2)
{
    ui->setupUi(this);
    setGeometry(0,30,1366,700);
    setMinimumSize(1366,700);
    setMaximumSize(1366,700);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Images/level2.jpg")));
    scene=new QGraphicsScene();
    scene->setSceneRect(0,0,1366,700);
    ui->graphicsView->setScene(scene);

    ave.append(new Capucho(1));
    ave.last()->setPos(140,450);
    ave.last()->setScale(1.2);
    scene->addItem(ave.last());

    cerdo.append(new Esmad(1));
    cerdo.last()->setPos(800,-10);
    scene->addItem(cerdo.last());

    cerdo.append(new Esmad(1));
    cerdo.last()->setPos(600,-1000);
    scene->addItem(cerdo.last());

    cerdo.append(new Esmad(1));
    cerdo.last()->setPos(1000,-2000);
    scene->addItem(cerdo.last());

    cerdo.append(new Esmad(1));
    cerdo.last()->setPos(900,-3000);
    scene->addItem(cerdo.last());

    int y1=555;
    for(int i=0; i<6;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(800,y1);
        y1-=40;
        scene->addItem(caja.last());
        }

    int y2=600;
    for(int i=0; i<1;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(600,y2);
        scene->addItem(caja.last());
        }

    int y3=600;
    for(int i=0; i<1;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(1000,y3);
        scene->addItem(caja.last());
        }
    score= new Score;
    scene->addItem(score);


    timer=new QTimer();
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    connect(timer,SIGNAL(timeout()),this,SLOT(agregar()));
    timer->start(3);

}

Level2::~Level2()
{
    delete ui;
}

void Level2::on_pushButton_clicked()
{
    timer->stop();
    scene->clear();
    close();
    ventana *v =new ventana;
    v->show();
}
void Level2::agregar()
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
        opciones = new Options2;
        opciones->show();
        scene->clear();
        close();
    }

}
