#ifndef CLASEBASE_H
#define CLASEBASE_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPainter>
#include <ui_mainwindow.h>
#define pi 3.14159265358979323846
class ClaseBase: public QGraphicsItem
{
public:
    ClaseBase();
    ClaseBase(double _vx, double _vy, double _masa, double _vida,int _nivel);
    void choque(ClaseBase *coli);
    void posicion();
    void aceleracion();

    //get
    double getMasa() const;
    double getVx() const;
    double getVy() const;
    double getVida() const;
    void setMasa(double value);

    //set
    void setVy(double value);
    void setVx(double value);
    void setAy(double value);
    void setVida(double value);
    void setNivel(int value);

    ~ClaseBase();




protected:
    double vida,masa,vx,vy,ay,ax,px,py,angulo,distancia;
    int nivel;
};


#endif // CLASEBASE_H
