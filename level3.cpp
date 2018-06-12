#include "level3.h"
#include "ui_level3.h"

#include "ventana.h"
#include "ui_ventana.h"
#include <QDebug>
#include <QFont>

Level3::Level3(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Level3)
{
    ui->setupUi(this);
    setGeometry(0,30,1366,700);
    setMinimumSize(1366,700);
    setMaximumSize(1366,700);
    ui->graphicsView->setBackgroundBrush(QBrush(QImage(":/Images/level3.jpg")));
    scene=new QGraphicsScene();
    scene->setSceneRect(0,0,1366,700);
    ui->graphicsView->setScene(scene);

    ave.append(new Capucho(1));
    ave.last()->setPos(140,450);
    ave.last()->setScale(1.2);
    scene->addItem(ave.last());

    cerdo.append(new Esmad(1));
    cerdo.last()->setPos(800,510);
    scene->addItem(cerdo.last());

    cerdo.append(new Esmad(1));
    cerdo.last()->setPos(795,-50);
    scene->addItem(cerdo.last());

    cerdo.append(new Esmad(1));
    cerdo.last()->setPos(1000,-1500);
    scene->addItem(cerdo.last());

    cerdo.append(new Esmad(1));
    cerdo.last()->setPos(470,-1000);
    scene->addItem(cerdo.last());

    cerdo.append(new Esmad(1));
    cerdo.last()->setPos(1100,-1000);
    scene->addItem(cerdo.last());

    cerdo.append(new Esmad(1));
    cerdo.last()->setPos(570,-1500);
    scene->addItem(cerdo.last());

    int y1=1000;
    for(int i=0; i<11;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(y1,600);
        y1-=43;
        scene->addItem(caja.last());
        }

    int y2=510;
    for(int i=0; i<2;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(740,y2);
        y2-=40;
        scene->addItem(caja.last());
        }

    int y3=510;
    for(int i=0; i<2;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(860,y3);
        y3-=42;
        scene->addItem(caja.last());
        }

    int y4=510;
    for(int i=0; i<4;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(1000,y4);
        y4-=42;
        scene->addItem(caja.last());
        }

    int y5=510;
    for(int i=0; i<4;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(570,y5);
        y5-=42;
        scene->addItem(caja.last());
        }

    int y6=880;
    for(int i=0; i<5;i++){
        caja.append(new Madera(1));
        caja.last()->setPos(y6,420);
        y6-=42;
        scene->addItem(caja.last());
        }

    score= new Score;
    scene->addItem(score);


    timer=new QTimer();
    connect(timer,SIGNAL(timeout()),scene,SLOT(advance()));
    connect(timer,SIGNAL(timeout()),this,SLOT(agregar()));
    timer->start(3);
}

Level3::~Level3()
{
    delete ui;
}
void Level3::on_pushButton_clicked()
{
    timer->stop();
    scene->clear();
    close();
    ventana *v =new ventana;
    v->show();
}
void Level3::agregar()
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
        opciones = new Options3;
        opciones->show();
        scene->clear();
        close();
    }

}
