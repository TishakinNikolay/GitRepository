#ifndef SD_H
#define SD_H
#include <QObject>
#include <QGraphicsPathItem>

class sd : public QObject, public QGraphicsPixmapItem
{
public:
    sd(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
};

#endif // SD_H
