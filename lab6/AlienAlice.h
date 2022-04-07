#ifndef ALIENALICE_H
#define ALIENALICE_H

#include "ScreenObject.h"

class AlienAlice : public ScreenObject {
    public:
        AlienAlice(int, int);
        virtual void draw();
        virtual void update(double);
    private:
        bool right;
};

#endif