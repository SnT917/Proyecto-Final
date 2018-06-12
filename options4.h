#ifndef OPTIONS4_H
#define OPTIONS4_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Options4;
}

class Options4 : public QDialog
{
    Q_OBJECT

public:
    explicit Options4(QWidget *parent = 0);
    ~Options4();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Options4 *ui;
    MainWindow * salir;
};

#endif // OPTIONS4_H
