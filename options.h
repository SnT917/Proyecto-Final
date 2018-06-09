#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class Options;
}

class Options : public QDialog
{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = 0);
    ~Options();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Options *ui;
    MainWindow * salir;
};

#endif // OPTIONS_H
