#ifndef OPTIONS3_H
#define OPTIONS3_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Options3;
}

class Options3 : public QDialog
{
    Q_OBJECT

public:
    explicit Options3(QWidget *parent = 0);
    ~Options3();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Options3 *ui;
    MainWindow * salir;
};

#endif // OPTIONS3_H
