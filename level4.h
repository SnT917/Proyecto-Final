#ifndef LEVEL4_H
#define LEVEL4_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QWidget>
#include "clasebase.h"
#include "options4.h"
#include "Madera.h"
#include "Capucho.h"
#include "Esmad.h"
#include "Score.h"

namespace Ui {
class Level4;
}

class Level4 : public QDialog
{
    Q_OBJECT

public:
    explicit Level4(QWidget *parent = 0);
    ~Level4();
public slots:
    void agregar();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Level4 *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    QList <Madera*> caja;
    QList<Capucho*> ave;
    QList <Esmad*> cerdo;
    QGraphicsTextItem *puntaje;
    Score * score;
    int contpajaros=15;
    Options4 * opciones;

};

#endif // LEVEL4_H
