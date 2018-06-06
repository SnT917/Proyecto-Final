#ifndef MULTIPLAYER_H
#define MULTIPLAYER_H

#include <login.h>
#include <registro.h>
#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/qsqlquery.h>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>

namespace Ui {
class multiplayer;
}

class multiplayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit multiplayer(QWidget *parent = 0);
    ~multiplayer();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::multiplayer *ui;
    QSqlDatabase dbmain;

};

#endif // MULTIPLAYER_H
