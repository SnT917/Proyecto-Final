#ifndef VENTANA_H
#define VENTANA_H

#include <QWidget>
#include <Qsize>
#include <QMainWindow>

namespace Ui {
class ventana;
}

class ventana : public QWidget
{
    Q_OBJECT

public:
    explicit ventana(QWidget *parent = 0);
    ~ventana();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();

private:
    Ui::ventana *ui;
};

#endif // VENTANA_H
