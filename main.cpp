#include <QApplication>
#include "GameController.h"
int main(int argc, char *argv[])
{
   QApplication a(argc,argv);
   GameController* gc = new GameController();
   gc->startGame(150);



    return a.exec();
}
