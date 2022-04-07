#ifndef ALIENJACK_H
#define ALIENJACK_H

#include "ScreenObject.h"

class AlienJack : public ScreenObject {
    public:
        AlienJack(int, int);
        virtual void draw();
        virtual void update(double);
    private:
        bool right;
};

#endif