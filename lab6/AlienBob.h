#ifndef ALIENBOB_H
#define ALIENBOB_H

#include "ScreenObject.h"

class AlienBob : public ScreenObject {
    public:
        AlienBob(int, int);
        virtual void draw();
        virtual void update(double);
    private: 
        int arms;
        bool right;
};

#endif