#ifndef LEVEL5_H
#define LEVEL5_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QTimer>
#include <QWidget>
#include "clasebase.h"
#include "options5.h"
#include "Madera.h"
#include "Capucho.h"
#include "Esmad.h"
#include "Score.h"

namespace Ui {
class Level5;
}

class Level5 : public QDialog
{
    Q_OBJECT

public:
    explicit Level5(QWidget *parent = 0);
    ~Level5();
public slots:
    void agregar();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Level5 *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    QList <Madera*> caja;
    QList<Capucho*> ave;
    QList <Esmad*> cerdo;
    QGraphicsTextItem *puntaje;
    Score * score;
    int contpajaros=15;
    Options5 * opciones;
};

#endif // LEVEL5_H
