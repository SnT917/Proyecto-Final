#include "objetos.h"

objetos::objetos(int _x, int _y, int _ancho, int _largo, QString _image)
{
    x=_x;
    y=_y;
    ancho=_ancho;
    largo=_largo;
    image=_image;
}
QRectF objetos:: boundingRect() const{
    return QRectF(x,y,ancho,largo);
}
void objetos::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QPixmap pixmap;
    pixmap.load(image);
    painter-> drawPixmap(boundingRect(), pixmap,pixmap.rect());
}
int objetos::getx(){
    return x;
}
int objetos::gety(){
    return y;
}

void objetos::setx(int x)
{
    this->x=x;
}

void objetos::sety(int y)
{
    this->y=y;
}


