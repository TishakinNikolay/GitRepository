#ifndef SNAKE_H
#define SNAKE_H
#include <QVector>
#include <QWidget>
#include "Scale.h"
#include "Body.h"
#include "SnakeHead.h"
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsPixmapItem>
enum Direction{ Right,Left, Up, Down};
class Snake: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT

private:
    int m_headX;
    int m_headY;
    int m_score;
    QVector<Scale*> m_snake;
    Direction m_direction;
    QGraphicsScene* m_scene;


public:
    Snake(QGraphicsScene*);
    void EatFood();
    int getScore();
    void render();
    virtual ~Snake();
    void move();
    void reset();
    bool canEat(int,int);
    bool isCoordFree(int,int);
signals:
    void snakeDied();

private:
   void startMoving(int);
   void addSegment();
   void keyPressEvent(QKeyEvent*);
};

#endif // SNAKE_H
