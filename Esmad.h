#ifndef ESMAD_H
#define ESMAD_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>

class Esmad:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Esmad(QGraphicsItem * parent=0);
};

#endif // ESMAD_H
