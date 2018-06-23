#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "Scale.h"

class Background : public Scale
{
public:
    Background();
    void render();
    virtual ~Background();
};

#endif // BACKGROUND_H
