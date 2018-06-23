 #include "GameController.h"
#include <QTimer>
#include <QObject>
#include <QDebug>
#include <QString>
#include <QFont>
GameController::GameController() : QObject()
{
    initialization();
}

void GameController::startGame(int time) {
    m_UpdateTime = time;
    m_timer->start(m_UpdateTime);
}
void GameController::initialization() {

    m_view = new QGraphicsView();
    m_scene = new QGraphicsScene();
    m_background = new Background();
    m_view->setScene(m_scene);
    m_view->setFixedSize(SCREEN_WIDTH,SCREEN_HEIGHT + SCREEN_PANEL_HEIGHT);
    m_scene->setSceneRect(0,0,SCREEN_WIDTH,SCREEN_HEIGHT + SCREEN_PANEL_HEIGHT);
    m_view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    m_scene->addItem(m_background);
    m_snake = new Snake(m_scene);
    m_scene->addItem(m_snake);
    m_food = new Food();
    createNewFood();
    m_scene->addItem(m_food);
    m_scoreText = new QGraphicsTextItem("Score is : " + QString::number(m_snake->getScore()));
    m_scoreText->setFont(QFont("Times new roma",14));
    m_scoreText->setPos(0,SCREEN_HEIGHT);
    m_scene->addItem(m_scoreText);
    m_timer = new QTimer();

    QObject:: connect(m_timer,SIGNAL(timeout()),this, SLOT(update()));
    QObject::connect(m_snake,SIGNAL(snakeDied()),this, SLOT(gameOver()));


    m_view->show();

}

void GameController::update() {
    m_snake->move();

    if(m_snake->canEat(m_food->getX(),m_food->getY())) {
       m_snake->EatFood();
       m_scoreText->setPlainText("Score is : " + QString::number(m_snake->getScore()));
       createNewFood();
    }

    render();
 }

void GameController::render() {
    m_snake->render();
    m_food->render();
}

void GameController::createNewFood() {
    do {
    m_food->newCoord();
    }while(m_snake->isCoordFree(m_food->getX(),m_food->getY()) == false);
}

void GameController::newGame() {
    m_table->clearFocus();
    m_scene->removeItem(m_table);
    delete m_table;
    m_snake->reset();
    m_scoreText->setPlainText("Score is : " + QString::number(m_snake->getScore()));
    createNewFood();
    m_timer->start(m_UpdateTime);
}

GameController::~GameController() {
    delete m_scene;
    delete m_view;
    delete m_snake;
    delete m_food;
    delete m_table;
    delete m_timer;
    delete m_background;
}

void GameController::gameOver() {
    m_timer->stop();
    m_table = new GameOverTable(m_scene);
    m_snake->clearFocus();
    m_table->setFlag(QGraphicsItem::ItemIsFocusable);
    m_table->setFocus();
    QObject::connect(m_table, SIGNAL(startNewGame()),this, SLOT(newGame()));
}
