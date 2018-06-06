#ifndef MADERA_H
#define MADERA_H
#include "clasebase.h"
#define dt 0.01
#define es 0.35

class Madera:public ClaseBase
{
public:
    Madera(int _nivel);
    QRectF boundingRect()const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    void colision();
    ~Madera();

protected:
    void advance(int phase);

};


#endif // CAJA_H

