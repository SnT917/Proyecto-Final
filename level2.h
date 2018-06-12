#ifndef LEVEL2_H
#define LEVEL2_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QWidget>
#include "clasebase.h"
#include "options2.h"
#include "Madera.h"
#include "Capucho.h"
#include "Esmad.h"
#include "Score.h"

namespace Ui {
class Level2;
}

class Level2 : public QDialog
{
    Q_OBJECT

public:
    explicit Level2(QWidget *parent = 0);
    ~Level2();
public slots:
    void agregar();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Level2 *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    QList <Madera*> caja;
    QList<Capucho*> ave;
    QList <Esmad*> cerdo;
    Score * score;
    int contpajaros=15;
    QGraphicsTextItem *puntaje;
    Options2 * opciones;

};

#endif // LEVEL2_H
