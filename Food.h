#ifndef FOOD_H
#define FOOD_H
#include "Scale.h"

class Food : public Scale
{
public:
    Food();
    void newCoord();
    void render();
    virtual ~Food();
};

#endif // FOOD_H
