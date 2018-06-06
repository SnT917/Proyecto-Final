#ifndef ESMAD_H
#define ESMAD_H

#include "clasebase.h"
#define dt 0.01
#define es 0.35

class Esmad:public ClaseBase{

public:
    Esmad(int _nivel);
    void colision();
    QRectF boundingRect()const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget);
    ~Esmad();
protected:
   void advance(int phase);
};

#endif // ESMAD_H
