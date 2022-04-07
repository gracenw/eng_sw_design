#ifndef ALIENKENZIE_H
#define ALIENKENZIE_H

#include "ScreenObject.h"

class AlienKenzie : public ScreenObject {
    public:
        AlienKenzie(int, int);
        virtual void draw();
        virtual void update(double);
    private:
        bool right;
};

#endif