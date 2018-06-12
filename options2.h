#ifndef OPTIONS2_H
#define OPTIONS2_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Options2;
}

class Options2 : public QDialog
{
    Q_OBJECT

public:
    explicit Options2(QWidget *parent = 0);
    ~Options2();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Options2 *ui;
    MainWindow * salir;
};

#endif // OPTIONS2_H
