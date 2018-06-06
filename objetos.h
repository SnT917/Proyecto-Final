#ifndef OBJETOS_H
#define OBJETOS_H

#include <QGraphicsItem>
#include <QPainter>

class objetos : public QGraphicsItem
{
private:
    int x,y,ancho,largo;
    QString image;
public:
    objetos(int _x,int _y, int _ancho,int _largo, QString _image);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    int getx();
    int gety();
    void setx(int);
    void sety(int);
};

#endif // OBJETOS_H
