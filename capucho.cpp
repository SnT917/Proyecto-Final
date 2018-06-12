#include "Capucho.h"
#include <QGraphicsScene>
#include "Capucho.h"
#include "Esmad.h"
#include "Madera.h"
#include "clasebase.h"
#include <QDebug>

Capucho::Capucho(int _nivel):ClaseBase(0,0,10,400000,_nivel), angulo(0),fr(0),puntaje(0)
{;}

void Capucho::colision()
{
    posicionave();
    QList<QGraphicsItem*> colisionadores = collidingItems(Qt::IntersectsItemBoundingRect);
    for (size_t i = 0, n = colisionadores.size(); i < n; ++i){

       Madera* caja = dynamic_cast<Madera*>(colisionadores[i]);  //define madera as colisionadores
       Esmad* cerdo= dynamic_cast<Esmad*>(colisionadores[i]);    //define madera as colisionadores
       if(caja){//capucho collides with caja

            if(y()+30>caja->y() and y()+30<caja->y()+30){
                vy=0;
                ay=0;

            }
       }

       if(cerdo)//capucho colides with esmad
           if(y()+30>cerdo->y() and y()+30<cerdo->y()+30){
              vy=0;
              ay=0;

           }
    }
}

void Capucho::posicionave()
{
    fr=-k*sqrt(pow(vx,2)+pow(vy,2))*9/masa; //friction
    if(y()>555 and x()>141){
        setPos(x(),555); //set the vertical limit to the scene
        vy*=-0.2;
        vx/=1.003;

    }
    if(scene()->collidingItems(this).isEmpty() and x()>160){
        ay=9.8;
    }
    //parabolic shot formulas
    px=x()+vx*dt+fr*cos(angulo)*dt*dt*.5;
    py=y()+vy*dt+(ay+fr*sin(angulo))*.5*dt*dt;
    setPos(px,py);

    vy+=(ay+fr*sin(angulo))*dt;
    vx+=fr*cos(angulo)*dt;

    angulo=atan2(vy,vx);
}


QRectF Capucho::boundingRect() const
{
    if(nivel==1) return QRectF(0,0,30,30);
}
void Capucho::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)  //set image
{
    QPixmap pixmap;
    pixmap.load(":/Images/capucho.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());  //set image to capucho
}


void Capucho::advance(int phase)
{
    if(!phase)return;

    colision();
    if((vx>0 and vx<=0.5) and x()>160 and isActive()){
        scene()->removeItem(this);//remove capucho
    }
}


void Capucho::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

    if(y()==450){
        setFlag(ItemIsMovable,true);
        setCursor(Qt::ClosedHandCursor);
        }

    QGraphicsItem::mousePressEvent(event);

}

void Capucho::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    double distancia;
    setCursor(Qt::PointingHandCursor);
    QGraphicsItem::mouseReleaseEvent(event);
    setFlag(ItemIsMovable,false);
//if the position leaves that range, it returns to the initial range
    if(x()>250 || y()>600 || y()<300)
        setPos(140,450);
    else{ //otherwise throw the capucho
        distancia=sqrt(pow(x()-140,2)+pow(y()-450,2));
        angulo=atan2(y()-450,x()-140);
        vx=-cos(angulo)*distancia;
        vy=-sin(angulo)*distancia;
        aceleracion(); }
}


Capucho::~Capucho()
{

}
