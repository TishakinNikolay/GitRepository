#include "Snake.h"
#include "GameController.h"
#include <QTimer>
#include <QKeyEvent>
#include <QObject>
#include <QDebug>
Snake::Snake(QGraphicsScene* scene) : QObject(), QGraphicsPixmapItem()
{ 
    m_snake.push_back( new SnakeHead());
    m_headX = GameController::SCREEN_WIDTH - m_snake.size() * Scale::SCALE_SIZE;
    m_headY = 0;
    m_score = 0;
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    this->m_scene = scene;

    for(int i = 0; i < m_snake.size(); ++i) {// Set position to all snake`s skales
       m_snake[i]->setPos(m_headX + i*Scale::SCALE_SIZE,0);
     }
     m_direction = Left;

    for(Scale* scale : m_snake) { // add snake to the scene
         scene->addItem(scale);
    }
    addSegment();
    addSegment();

}
void Snake::reset() {
    for(Scale* s : m_snake) {
        m_scene->removeItem(s);
        delete s;

    }
    m_snake.erase(m_snake.begin(),m_snake.end());
    m_snake.push_back( new SnakeHead());

    m_headX = GameController::SCREEN_WIDTH - m_snake.size() * Scale::SCALE_SIZE;
    m_headY = 0;
    m_score = 0;

    for(int i = 0; i < m_snake.size(); ++i) {// Set position to all snake`s skales
       m_snake[i]->setPos(m_headX + i*Scale::SCALE_SIZE,0);
     }
     m_direction = Left;

    for(Scale* scale : m_snake) { // add snake to the scene
         m_scene->addItem(scale);
    }
    addSegment();
    addSegment();
     setFocus();
}
bool Snake::canEat(int x, int y) {
    if(x == m_headX && y == m_headY) return true;
    return false;
}
bool Snake::isCoordFree(int x, int y) {
    for(Scale* s : m_snake) {
        if(s->getX() == x && s->getY() == y) return false;
    }
    return true;
}
void Snake::move() {
    int oldY;
    int oldX;
    int y;
    int x;

     switch(m_direction) {
      case Right:
         if(m_headX + Scale::SCALE_SIZE >= GameController::SCREEN_WIDTH) {
             emit snakeDied();
             return;
         }
         if(!isCoordFree(m_headX + Scale::SCALE_SIZE,m_headY)) {
             emit snakeDied();
             return;
         }
         oldX = static_cast<int>(m_snake[0]->x());
         oldY = static_cast<int>(m_snake[0]->y());
         m_snake[0]->setCoords(oldX + Scale::SCALE_SIZE,oldY);
         for(int i = 1; i < m_snake.size(); ++i) {
             x = static_cast<int>(m_snake[i]->x());
             y = static_cast<int>(m_snake[i]->y());
             m_snake[i]->setCoords(oldX,oldY);
             oldX = x;
             oldY = y;
         }
         m_headX+=Scale::SCALE_SIZE;
         break;

      case Left:
         if(m_headX <= 0) {
            emit snakeDied();
             return;
         }
         if(!isCoordFree(m_headX - Scale::SCALE_SIZE,m_headY)) {
             emit snakeDied();
             return;
         }
         oldX = static_cast<int>(m_snake[0]->x());
         oldY = static_cast<int>(m_snake[0]->y());
         m_snake[0]->setCoords(oldX - Scale::SCALE_SIZE,oldY);
         for(int i = 1; i < m_snake.size(); ++i) {
             x = static_cast<int>(m_snake[i]->x());
             y = static_cast<int>(m_snake[i]->y());
             m_snake[i]->setCoords(oldX,oldY);
             oldX = x;
             oldY = y;
         }
         m_headX-=Scale::SCALE_SIZE;
         break;

      case Up:
         if(m_headY <= 0) {
             emit snakeDied();
             return;
         }
         if(!isCoordFree(m_headX,m_headY -  Scale::SCALE_SIZE)) {
             emit snakeDied();
             return;
         }
         oldX = static_cast<int>(m_snake[0]->x());
         oldY = static_cast<int>(m_snake[0]->y());
         m_snake[0]->setCoords(oldX,oldY - Scale::SCALE_SIZE);
         for(int i = 1; i < m_snake.size(); ++i) {
             x = static_cast<int>(m_snake[i]->x());
             y = static_cast<int>(m_snake[i]->y());
             m_snake[i]->setCoords(oldX,oldY);
             oldX = x;
             oldY = y;
         }
         m_headY-=Scale::SCALE_SIZE;
         break;

      case Down:
         if(m_headY + Scale::SCALE_SIZE >= GameController::SCREEN_HEIGHT) {
             emit snakeDied();
             return;
         }
         if(!isCoordFree(m_headX,m_headY +  Scale::SCALE_SIZE)) {
             emit snakeDied();
             return;
         }
         oldX = static_cast<int>(m_snake[0]->x());
         oldY = static_cast<int>(m_snake[0]->y());
         m_snake[0]->setCoords(oldX,oldY + Scale::SCALE_SIZE);
         for(int i = 1; i < m_snake.size(); ++i) {
             x = static_cast<int>(m_snake[i]->x());
             y = static_cast<int>(m_snake[i]->y());
             m_snake[i]->setCoords(oldX,oldY);
             oldX = x;
             oldY = y;
         }
         m_headY+=Scale::SCALE_SIZE;
         break;
     }
}

void Snake::render() {
    for(Scale* s : m_snake) {
        s->setPos(s->getX(),s->getY());
    }
}

void Snake::addSegment() {
    Scale *s = new Body();
    m_snake.push_back(s);
    m_scene->addItem(s);
}

Snake::~Snake(){
    for(Scale* s : m_snake) {
        delete s;
    }
}
void Snake::keyPressEvent(QKeyEvent* event) {
    switch (event->key()) {
     case Qt::Key_Up:
        if(m_direction == Down) return;
        m_direction = Up;
        m_snake[0]->setPixmap(QPixmap(":Images/Resourses/UpHead.png"));
        break;
    case Qt::Key_Down:
        if(m_direction == Up) return;
        m_direction = Down;
        m_snake[0]->setPixmap(QPixmap(":Images/Resourses/DownHead.png"));
       break;
    case Qt::Key_Right:
        if(m_direction == Left) return;
        m_direction = Right;
        m_snake[0]->setPixmap(QPixmap(":Images/Resourses/RightHead.png"));
       break;
    case Qt::Key_Left:
        if(m_direction == Right) return;
        m_direction = Left;
        m_snake[0]->setPixmap(QPixmap(":Images/Resourses/LeftHead.png"));
       break;
    }
}
int Snake::getScore() {return m_score;}
void Snake::EatFood() {

   m_score++;
   addSegment();
}
