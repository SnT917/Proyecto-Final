#ifndef LEVEL1_H
#define LEVEL1_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QWidget>
#include "clasebase.h"
#include "Madera.h"
#include "Capucho.h"
#include "Esmad.h"
#include "Score.h"

namespace Ui {
class Level1;
}

class Level1 : public QDialog
{
    Q_OBJECT

public:
    explicit Level1(QWidget *parent = 0);
    ~Level1();
public slots:
    void agregar();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Level1 *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    QList <Madera*> caja;
    QList<Capucho*> ave;
    QList <Esmad*> cerdo;
    QGraphicsTextItem *puntaje;

};

#endif // LEVEL1_H
