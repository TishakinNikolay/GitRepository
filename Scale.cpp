#include "Scale.h"

Scale::Scale() : QGraphicsPixmapItem()
{

}
int Scale::getX() {return m_x;}
int Scale::getY() {return m_y;}
void Scale::setCoords(int x, int y)
{
  m_x = x;
  m_y = y;
}
Scale::~Scale()
{
}
