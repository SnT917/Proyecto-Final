#include "Madera.h"
#include <QGraphicsScene>

Madera::Madera(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    // set graphic
    setPixmap(QPixmap(":/images/Madera.png"));
}

