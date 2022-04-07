#include "Bullet.h"
#include "globals.h"

Bullet :: Bullet() : ScreenObject(63, 121) {}

void Bullet :: draw() {
            if(visible) uLCD.filled_rectangle(x, y, (x + 1), (y - 2), WHITE);
        }

void Bullet :: update(double xacc) {
            if(visible) {
                if(y > 1) {
                    y = y - 1;
                    uLCD.filled_rectangle(x, (y + 1), (x + 1), (y - 1), BLACK);
                }
                else if(y == 1) {
                    visible = false; 
                    uLCD.filled_rectangle(x, (y + 1), (x + 1), (y - 1), BLACK);
                }
                else {
                    visible = false;
                    uLCD.filled_rectangle(x, y, (x + 1), (y - 2), BLACK);
                }
            }
            else {
                uLCD.filled_rectangle(x, y, (x + 1), (y - 1), BLACK);
            }
        }