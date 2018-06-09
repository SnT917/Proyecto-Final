#include "mainwindow.h"
#include <QApplication>
#include <QMediaPlayer>
#include <QSplashScreen>
#include <QTimer>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QSplashScreen *splash = new QSplashScreen;          //add splash screen
    splash->setPixmap(QPixmap(":/Images/splash.png"));
    splash->show();

    MainWindow w;

    QTimer::singleShot(4000,splash,SLOT(close()));    //timer conect with splash and close
    QTimer::singleShot(4000,&w,SLOT(show()));         //timer conect with the application and show

//    QMediaPlayer * music = new QMediaPlayer();        //add music to the main
//    music->setMedia(QUrl("qrc:/Sounds/musica.mp3"));
//    music->play();


    return a.exec();
}
