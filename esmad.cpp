#include "Esmad.h"
#include "Madera.h"
#include "Capucho.h"
#include "clasebase.h"
#include "level1.h"


Esmad::Esmad(int _nivel):ClaseBase(0,0,20,65000,_nivel){}

QRectF Esmad::boundingRect() const
{
    if(nivel==1)return QRectF(0,0,40,40);
    else return QRectF(-20,-20,40,40);
}

void Esmad::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/Images/esmad.png");
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());
}


void Esmad::advance(int phase)
{
    if(!phase)return;
    colision();

    if(vida<=0){
        scene()->removeItem(this);
    }
}


void Esmad::colision(){
    posicion();
    QList<QGraphicsItem*> colisionadores = collidingItems(Qt::IntersectsItemBoundingRect);
    for (size_t i = 0, n = colisionadores.size(); i < n; ++i){
        Capucho* ave=dynamic_cast<Capucho*>(colisionadores[i]);
        Madera* caja=dynamic_cast<Madera*>(colisionadores[i]);
        Esmad* cerdo=dynamic_cast<Esmad*>(colisionadores[i]);

        if(ave){ //capucho collides with esmad
            if(ave->x()+30>=x() and !(ave->y()+30>y() and ave->y()+30<y()+30))ave->setPos(ave->x()-2,ave->y());
            choque(ave);}

        if(caja){//esmad collides with caja
            if((caja->y()+40>y() and caja->y()+40<y()+40 ) or (y()+40>caja->y() and y()+40<caja->y()+40)){
                 ay=0;
                 vy=0;
                 caja->setAy(0);
                 caja->setVy(0);
            }

            if(x()<caja->x() and vx>0 and (x()+40>caja->x() and x()+40<caja->x()+40))setPos(caja->x()-2,y());
            else if(caja->x()<x() and caja->getVx()>0 and(caja->x()+40>x() and caja->x()+40<x()+40)and !((caja->y()+40>y() and caja->y()+40<y()+40 ) or (y()+40>caja->y() and y()+40<caja->y()+40)))caja->setPos(x()-42,caja->y());
            else if(x()>caja->x()+40 and vx<0 )setPos(caja->x()+42,y());
            choque(caja);
        }

        if(cerdo){ //esmad collides with another esmad
            if(x()<cerdo->x() and vx>0)setPos(cerdo->x()-42,y());
            else if(x()>cerdo->x()+40 and vx<0)setPos(caja->x()+42,y());
            choque(cerdo);}
    }
}



Esmad::~Esmad()  //destructor
{

}
