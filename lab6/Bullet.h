#ifndef BULLET_H
#define BULLET_H

#include "ScreenObject.h"

class Bullet : public ScreenObject {
    public:
        Bullet();
        virtual void draw();
        virtual void update(double);
};

#endif