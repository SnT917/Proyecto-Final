#include "clasebase.h"
#include <qDebug>
#define dt 0.01
#define es 0.35


ClaseBase::ClaseBase():vx(0),vy(0),masa(0),ay(0),ax(0),vida(0),distancia(0),angulo(0)  //constructor
{}

ClaseBase::ClaseBase(double _vx, double _vy, double _masa, double _vida,int _nivel):ax(0),distancia(151),angulo(0) //constructor
{
    vx=_vx;
    vy=_vy;
    masa=_masa;
    vida=_vida;
    nivel=_nivel;
    setPos(140,450);
    aceleracion();
}

void ClaseBase::posicion()
{

    if(y()>=555 ){    //to detect the collision in the first row
        ay=0;
        vy=0;
        vx/=1.003;
        px=x()+vx*dt;
        py=y()+vy*dt+ay*0.5*dt*dt;
        setPos(px,555);

        vy+=ay*dt;
    }
    if(y()<555 ){     //to detect the collision in the other rows

        px=x()+vx*dt;
        py=y()+vy*dt+ay*0.5*dt*dt;
        setPos(px,py);
        vy+=ay*dt;

        if(ay==0){
            ay=9.8;
        }
    }


}

void ClaseBase::aceleracion()   //if the capucho is launched, its acceleration changes
{
    if(y()==450 and x()==140){  //inicial position of the capucho
        ay=0;
    }
    else{
        ay=9.8;
    }


}
void ClaseBase::choque(ClaseBase *coli)
{
    double _vidaC;
    _vidaC=coli->getVida()-(sqrt(pow(vx,2)+pow(vy,2))*masa)+(sqrt(pow(coli->getVx(),2)+pow(coli->getVy(),2))*coli->getMasa());
    coli->setVida(_vidaC);
    vida-=sqrt(pow(coli->getVx(),2)+pow(coli->getVy(),2))*coli->getMasa()+(sqrt(pow(vx,2)+pow(vy,2))*masa);

    //restitution coefficient used in lab6
    //used to observe the collisions, otherwise it would go through the objects
    double u1=vx,v2;
    vx=((masa-coli->getMasa()*es)*vx+coli->getMasa()*(1+es)*coli->getVx())/(masa+coli->getMasa());
    v2=((coli->getMasa()-masa*es)*coli->getVx()+masa*(1+es)*u1)/(masa+coli->getMasa());
    coli->setVx(v2);//set the value of velocity in x
    u1=vy;
    vy=((masa-coli->getMasa()*es)*vy+coli->getMasa()*(1+es)*coli->getVy())/(masa+coli->getMasa());
    v2=((coli->getMasa()-masa*es)*coli->getVy()+masa*(1+es)*u1)/(masa+coli->getMasa());
    coli->setVy(v2);//set the value of velocity in y
}


//set and get methods

double ClaseBase::getMasa() const
{
    return masa;
}

double ClaseBase::getVx() const
{
    return vx;
}

double ClaseBase::getVy() const
{
    return vy;
}

void ClaseBase::setVy(double value)
{
    vy = value;
}

void ClaseBase::setVx(double value)
{
    vx = value;
}

void ClaseBase::setAy(double value)
{
    ay = value;
}

void ClaseBase::setVida(double value)
{
    vida = value;
}

void ClaseBase::setNivel(int value)
{
    nivel = value;
}


double ClaseBase::getVida() const
{
    return vida;
}

ClaseBase::~ClaseBase()
{

}

void ClaseBase::setMasa(double value)
{
    masa = value;
}
