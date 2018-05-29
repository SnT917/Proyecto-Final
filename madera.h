#ifndef MADERA_H
#define MADERA_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Madera:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Madera(QGraphicsItem * parent=0);
};

#endif // MADERA_H
