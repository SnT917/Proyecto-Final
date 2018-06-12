#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    score = 15;

    // draw the text
    setPlainText(QString("Capuchos: ") + QString::number(score)); // Score: 0
    setDefaultTextColor(Qt::white);
    setFont(QFont("times",16));
}

void Score::increase(){
    score-=1;
    setPlainText(QString("Capuchos: ") + QString::number(score)); // Score-1
}

int Score::getScore(){
    return score;
}
