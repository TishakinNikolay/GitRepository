#include "sd.h"
#include <QDebug>
#include <QKeyEvent>
sd::sd(QGraphicsItem * parent) : QObject(), QGraphicsPixmapItem(parent)
{
    setFlag(QGraphicsItem::ItemIsFocusable);
    setFocus();
    qDebug() <<"Created sd";
}
void sd::keyPressEvent(QKeyEvent* event) {
    qDebug() << event->key();
}
