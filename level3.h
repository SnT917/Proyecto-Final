#ifndef LEVEL3_H
#define LEVEL3_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QWidget>
#include "clasebase.h"
#include "options3.h"
#include "Madera.h"
#include "Capucho.h"
#include "Esmad.h"
#include "Score.h"

namespace Ui {
class Level3;
}

class Level3 : public QDialog
{
    Q_OBJECT

public:
    explicit Level3(QWidget *parent = 0);
    ~Level3();
public slots:
    void agregar();

private slots:
    void on_pushButton_clicked();


private:
    Ui::Level3 *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    QList <Madera*> caja;
    QList<Capucho*> ave;
    QList <Esmad*> cerdo;
    QGraphicsTextItem *puntaje;
    Score * score;
    int contpajaros=15;
    Options3 * opciones;
};

#endif // LEVEL3_H
