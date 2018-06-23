#ifndef GAMEOVERTABLE_H
#define GAMEOVERTABLE_H
#include "Scale.h"


class GameOverTable :public QObject, public Scale
{
    Q_OBJECT
public:
    GameOverTable(QGraphicsScene*);
  virtual  ~GameOverTable();
    void keyPressEvent(QKeyEvent* event);
signals:
   void startNewGame();
};

#endif // GAMEOVERTABLE_H
