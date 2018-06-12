#ifndef CAPUCHO_H
#define CAPUCHO_H
#include "clasebase.h"
#define dt 0.01
#define es 0.35
//#define k 1.55*0.01*3.14159265358979323846*0.5
//#define r 0.2

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>

class Capucho: public ClaseBase{

public:
    Capucho(int _nivel);
    QRectF boundingRect()const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void colision();
    void posicionave();
    ~Capucho();
    int k =1.55*0.01*3.14159265358979323846*0.5;
    double getPuntaje() const;
    void setPuntaje(double value);
    int puntaje;
private:
    double angulo,fr;

protected:
    void advance(int phase);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CAPUCHO_H
