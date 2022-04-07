#include "Ship.h"
#include "globals.h"

Ship :: Ship() : ScreenObject(63, 125) {}

void Ship :: draw() {
            uLCD.filled_rectangle((x - 7), y, (x + 7), (y - 3), WHITE);
        }

void Ship :: update(double xacc) {
            if(xacc >= 0.5) { //right fast
                if(x < 119) { 
                    x = x + 2;
                    uLCD.filled_rectangle((x - 9), y, (x + 5), (y - 3), BLACK);
                }
                else if(x == 119) { 
                    x = x + 1;
                    uLCD.filled_rectangle((x - 8), y, (x + 6), (y - 3), BLACK);
                }
            }
            else if(xacc <= -0.5) { //left fast
                if(x > 8) { 
                    x = x - 2;
                    uLCD.filled_rectangle((x - 5), y, (x + 9), (y - 3), BLACK);
                }
                else if(x == 8) { 
                    x = x - 1;
                    uLCD.filled_rectangle((x - 6), y, (x + 8), (y - 3), BLACK);
                }
            }
            else if(xacc >= 0.2 && x <= 119) { //right slow
                x = x + 1;
                uLCD.filled_rectangle((x - 8), y, (x + 6), (y - 3), BLACK);
            }
            else if(xacc <= -0.2 && x >= 8) { //left slow
                x = x - 1;
                uLCD.filled_rectangle((x - 6), y, (x + 8), (y - 3), BLACK);
            }
        }