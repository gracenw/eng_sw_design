#ifndef SCREENOBJECT_H
#define SCREENOBJECT_H

class ScreenObject {
    public:
        ScreenObject(int, int);
        virtual void draw() = 0;
        virtual void update(double) = 0;
        void setX(int);
        int getX();
        void setY(int);
        int getY();
        void setVisibility(bool);
        bool getVisibility();
    protected: 
        int x;
        int y;
        bool visible;
};

#endif