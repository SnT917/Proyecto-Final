#ifndef CAPUCHO_H
#define CAPUCHO_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Capucho:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Capucho(QGraphicsItem * parent=0);
};

#endif // CAPUCHO_H
