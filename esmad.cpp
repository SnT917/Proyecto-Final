#include "Esmad.h"
#include <QGraphicsScene>
#include <QKeyEvent>

Esmad::Esmad(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    // set graphic
    setPixmap(QPixmap(":/images/esmad.png"));
}
