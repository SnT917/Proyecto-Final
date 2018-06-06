#ifndef LOGIN_H
#define LOGIN_H

#include <QtSql/QSqlDatabase>
#include <QtSql/qsqlquery.h>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QWidget>
#include "multi.h"

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT

public:
    explicit login(QWidget *parent = 0);
    ~login();

private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::login *ui;
    multi * Multi;

};

#endif // LOGIN_H

