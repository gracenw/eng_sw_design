#ifndef SHIP_H
#define SHIP_H

#include "ScreenObject.h"

class Ship : public ScreenObject {
    public:
        Ship();
        virtual void draw();
        virtual void update(double);
};

#endif