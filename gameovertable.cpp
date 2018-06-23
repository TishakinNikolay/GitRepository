#include "gameovertable.h"
#include <QtDebug>
#include "GameController.h"
#include <QGraphicsScene>
GameOverTable::GameOverTable(QGraphicsScene* scene) : QObject(), Scale()
{
 setPixmap(QPixmap(":/Images/Resourses/GameOver.png"));
 setPos((GameController::SCREEN_WIDTH - pixmap().width()) / 2, (GameController::SCREEN_HEIGHT - pixmap().height()) / 2);
 scene->addItem(this);
}
GameOverTable::~GameOverTable() {}
void GameOverTable::keyPressEvent(QKeyEvent* event) {
   emit startNewGame();
}
