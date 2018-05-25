#include "Game.h"
#include <QGraphicsTextItem>
#include <QFont>
#include "Capucho.h"
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>

Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/images/fondo.jpg")));

    // make the newly created scene the scene to visualize (since Game is a QGraphicsView Widget,
    // it can be used to visualize scenes)
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    capucho = new Capucho();
    capucho->setPos(400,500);
    capucho->setFlag(QGraphicsItem::ItemIsFocusable);
    capucho->setFocus();
    scene->addItem(capucho);

    score = new Score();
    scene->addItem(score);

    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/musica.mp3"));
    music->play();

    show();
}
