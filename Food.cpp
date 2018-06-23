#include "Food.h"
#include <qglobal.h>
#include <QTime>
#include <qrandom.h>
#include "GameController.h"
Food::Food() :  Scale()
{
    QTime time = QTime::currentTime();
    qsrand(static_cast<uint>(time.msec()));
    setPixmap(QPixmap(":/Images/Resourses/Food.png"));
}
void Food::newCoord() {
    m_x = (qrand() % (GameController::SCREEN_WIDTH / SCALE_SIZE)) * SCALE_SIZE;
    m_y = (qrand() % (GameController::SCREEN_HEIGHT / SCALE_SIZE)) * SCALE_SIZE;
}
void Food::render() {
    setPos(m_x,m_y);
}
Food::~Food() {}
