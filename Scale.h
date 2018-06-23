#ifndef SCALE_H
#define SCALE_H
#include <QGraphicsPixmapItem>

class Scale : public QGraphicsPixmapItem
{
public:
    int m_x;
    int m_y;
    const static int SCALE_SIZE = 20;
public:
    Scale();
    int getX();
    int getY();
    void setCoords(int,int);
    virtual ~Scale();
};

#endif // SCALE_H
