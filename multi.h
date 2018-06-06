#ifndef MULTI_H
#define MULTI_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QTimer>
#include <time.h>
#include <ctime>
#include <QKeyEvent>
#include "objetos.h"

namespace Ui {
class multi;
}

class multi : public QMainWindow
{
    Q_OBJECT

public:
    explicit multi(QWidget *parent = 0);
    ~multi();
public slots:
    void actualizar();
private slots:
    void keyPressEvent(QKeyEvent *accion);
    void keyReleaseEvent(QKeyEvent *accion);

private:
    Ui::multi *ui;
    QGraphicsScene *scene;
    QGraphicsLineItem *l1;
    QGraphicsLineItem *l2;
    QGraphicsLineItem *l3;
    QGraphicsLineItem *l4;
    QTimer *timer;
    multi * nuevo;
    objetos*dinosaurio,*cactus,*downdino;
    int dist=7,cont=0,cont2=1,cont3=0,puntaje=0,puntaje2=0;
    bool saltar=false,reinicio = false;


};

#endif // MULTI_H
