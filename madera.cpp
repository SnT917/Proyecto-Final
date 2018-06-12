#include "Madera.h"
#include "Capucho.h"
#include "Esmad.h"
#include "clasebase.h"
#include <QDebug>

Madera::Madera(int _nivel):ClaseBase(0,0,20,80000,_nivel)
{}


QRectF Madera::boundingRect() const
{
    if(nivel==1)return QRectF(0,0,40,40);
}


void Madera::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPixmap pixmap;
    pixmap.load(":/Images/Madera.png");   //set image to madera
    painter->drawPixmap(boundingRect(),pixmap,pixmap.rect());

}

void Madera::advance(int phase)
{
    if(!phase)return;

    colision(); //check the collision
    if(vida<=0){
        scene()->removeItem(this);//remove item madera
    }
}

void Madera::colision()
{
    posicion(); //check and set the position

    QList<QGraphicsItem*> colisionadores = collidingItems(Qt::IntersectsItemBoundingRect);
    for (size_t i = 0, n = colisionadores.size(); i < n; ++i){
        Madera *caja = dynamic_cast<Madera*>(colisionadores[i]);
        Capucho *ave=dynamic_cast<Capucho*>(colisionadores[i]);
       if(ave){//capucho collides with caja
            if(ave->x()>=x() and !(ave->y()+30>y() and ave->y()+30<y()+30))ave->setPos(ave->x()-2,ave->y());
           choque(ave);}

        if(caja){ //caja collides with caja
           if(y()==caja->y() or ((y()+2>caja->y() and y()+2<caja->y()+2) or (caja->y()+2>y() and caja->y()+2<y()+2)))
               choque(caja);

           if((caja->y()+40>y() and caja->y()+40<y()+42 ) or (y()+40>caja->y() and y()+40<caja->y()+42)){
                vx/=1.0003;
                caja->setVx(caja->getVx()/1.003);
                ay=0;
                vy=0;
                caja->setAy(0);
                caja->setVy(0);

                //para ver bien cuando una caja choca con otra
                if((y()+40>caja->y() and y()+40<caja->y()+2) and scene()->collidingItems(caja).length()==1 and caja->y()<555)caja->aceleracion();
                if((caja->y()+40>y() and caja->y()+40<y()+2) and scene()->collidingItems(this).length()==1 and y()<555)aceleracion();}
        }

        }
    }



Madera::~Madera()  //destructor
{

}


