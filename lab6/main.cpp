#include "globals.h"
#include "ScreenObject.h"
#include "AlienBob.h"
#include "AlienAlice.h"
#include "AlienJack.h"
#include "AlienKenzie.h"
#include "Ship.h"
#include "Bullet.h"

PinDetect pb(p21);
Speaker speaker(p24);
uLCD_4DGL uLCD(p9, p10, p11);
Serial pc(USBTX,USBRX);

//main
bool shot = false; //pb pressed
bool fired = false; //bullet onscreen

void pb_hit_callback(void) {
    speaker.PlayNote(600, 0.1, 0.2);
    shot = true;
}

int main() {
    uLCD.printf("LAME attack");
    wait(2);
    uLCD.cls();
    
    uLCD.baudrate(3000000);
    wait(1);
    
    pb.mode(PullUp);
    wait(0.01);
    pb.attach_deasserted(&pb_hit_callback);
    pb.setSampleFrequency();
    
    MMA8452 acc(p28, p27, 40000);
    acc.setBitDepth(MMA8452::BIT_DEPTH_12);
    acc.setDynamicRange(MMA8452::DYNAMIC_RANGE_4G);
    acc.setDataRate(MMA8452::RATE_100);
    
    double xacc = 0; 
    
    Timer t; t.start();
    ScreenObject* objs[8];
    
    //set positions of objects
    srand(time(0));
    for(int i = 0; i < 6; i++) {
        int x = 5 + rand() % 118;
        int y = 10 + (i * 15);
        int type = rand() % 4;
        if(type == 0) objs[i] = new AlienAlice(x, y);
        else if(type == 1) objs[i] = new AlienBob(x, y);
        else if(type == 2) objs[i] = new AlienJack(x, y);
        else objs[i] = new AlienKenzie(x, y);
    }
    objs[6] = new Ship();
    objs[7] = new Bullet();
    objs[7]->setVisibility(false);
    
    //initial draw
    for(int i = 0; i < 8; i++) { 
        objs[i]->draw();
    }
    
    int dead = 0;
    //begin game
    while(dead < 6) { 
        if(!acc.isXYZReady()) {
            wait(0.01);
            continue;
        }
        else acc.readYGravity(&xacc);
        
        //check location of bullet, kill aliens
        if(shot && !fired) { 
            objs[7]->setVisibility(true);
            objs[7]->setX(objs[6]->getX());
            objs[7]->setY(121);
            shot = false;
            fired = true;
        }
        if(objs[7]->getVisibility()) {
            for(int i = 0; i < 6; i++) { //loop through aliens
                int ox = objs[i]->getX();
                int bx = objs[7]->getX();
                int oy = objs[i]->getY();
                int by = objs[7]->getY();
                if(objs[i]->getVisibility()) {
                        if(bx <= (ox + 11) && bx >= ox && by <= (oy + 8) && by >= oy) {
                            speaker.PlayNote(900, 0.1, 0.2);
                            speaker.PlayNote(500, 0.1, 0.2);
                            speaker.PlayNote(900, 0.1, 0.2);
                            objs[i]->setVisibility(false); //alien disappears
                            objs[7]->setVisibility(false); //bullet disappears
                            fired = false; //no firing shot on screen
                            dead++;
                        }
                }
            }
        }
        else fired = false;
        uLCD.background_color(BLACK);
        //update objects, xacc arg only used in ship
        for(int i = 0; i < 8; i++) {
            objs[i]->update(xacc); //update object
            objs[i]->draw(); //draw object based on update
        }
    }
    
    //display end results
    t.stop();
    int time = t.read();
    
    uLCD.cls();
    uLCD.printf("congratulations! \n\nthe aliens have \nbeen defeated!\n\n");
    uLCD.printf("time to save the \nworld: \n\n%i seconds", time);
    
    //free objects
    for(int i = 0; i < 8; i++) {
        delete objs[i];
    }
}