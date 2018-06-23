#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsTextItem>
#include "Snake.h"
#include "Food.h"
#include "gameovertable.h"
#include "background.h"
#include <QSlider>
class GameController: QObject
{
    Q_OBJECT
public:
    const static int SCREEN_PANEL_HEIGHT = 30;
    const static int SCREEN_WIDTH = 600;
    const static int SCREEN_HEIGHT = 600;
public:
    GameController();
   virtual ~GameController();
    void startGame(int);
public slots:
    void update();
    void gameOver();
    void newGame();
private:
    void createNewFood();
    void render();
    void initialization();
private:
    Background* m_background;
    GameOverTable* m_table;
    QGraphicsTextItem* m_scoreText;
    Snake* m_snake;
    Food* m_food;
    QGraphicsScene* m_scene;
    QGraphicsView* m_view;
    QTimer* m_timer;
    int m_UpdateTime;
};

#endif // GAMECONTROLLER_H
