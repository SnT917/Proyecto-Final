#include "Capucho.h"
#include <QGraphicsScene>
#include <QKeyEvent>

Capucho::Capucho(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    // set graphic
    setPixmap(QPixmap(":/images/capucho.png"));
}
