#include "background.h"

Background::Background(): Scale()
{
 setPixmap(QPixmap(":/Images/Resourses/Background.png"));
 setPos(0,0);
}
Background::~Background(){}
