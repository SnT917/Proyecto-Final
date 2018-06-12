#ifndef OPTIONS5_H
#define OPTIONS5_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Options5;
}

class Options5 : public QDialog
{
    Q_OBJECT

public:
    explicit Options5(QWidget *parent = 0);
    ~Options5();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Options5 *ui;
    MainWindow * salir;
};

#endif // OPTIONS5_H
