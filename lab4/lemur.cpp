#include "mbed.h"
#include "uLCD_4DGL.h"
#include "Speaker.h"
#include "PinDetect.h"

#define YELLOW 0xFFFF00
#define CYAN   0x00FFFF
#define ORANGE 0xFFA500

PinDetect pbLeft(p21);
PinDetect pbRight(p22);
PinDetect pbExit(p23);
Speaker speaker(p24);
uLCD_4DGL uLCD(p9, p10, p11);

bool game_state=true;

void hit_callback(void) {
    game_state=false;
    uLCD.cls();
    uLCD.printf("goodbye lemur!");
}

void welcome_screen() {
    uLCD.printf("hello lemur!");
    speaker.PlayNote(600,0.5,0.2);
    speaker.PlayNote(700,0.5,0.2);
    speaker.PlayNote(900,0.25,0.2);
    speaker.PlayNote(800,0.5,0.2);
    speaker.PlayNote(750,0.25,0.2);
    speaker.PlayNote(900,0.5,0.2);
    speaker.PlayNote(950,0.5,0.2);
}

int color_assign() {
    int color=rand() %6;
    if(color==0) return YELLOW;
    else if(color==1) return RED;
    else if(color==2) return GREEN;
    else if(color==3) return BLUE;
    else if(color==4) return CYAN;
    else return ORANGE;
}

void randomize_board(int &left, int &right){
    int y=10;
    
    //left
    int xL=10;
    for(int w=0;w<=40;w+=20) {
        for(int h=0;h<=100;h+=20) {
            int shape=rand() %6;
            if((shape==0 && left<15) || (left==0 && w==40 && h==100)){
                int radius=rand() %7 +3;
                uLCD.filled_circle(xL+w,y+h,radius,color_assign());
                left++;
            }
            else if(shape==1 && left<15) {
                int half_length=rand() %7 +3;
                int x1=(xL+w)-half_length;
                int x2=(xL+w)+half_length;
                int y1=(y+h)-half_length;
                int y2=(y+h)+half_length;
                uLCD.filled_rectangle(x1,y1,x2,y2,color_assign());
                left++;
            }
            else if(shape==2 && left<15) {
                int half_length=rand() %7 +3;
                int x1=(xL+w);
                int y1=(y+h)-half_length;
                int x2=(xL+w)-half_length;
                int y2=(y+h)+half_length;
                int x3=(xL+w)+half_length;
                int y3=(y+h)+half_length;
                uLCD.triangle(x1,y1,x2,y2,x3,y3,color_assign());
                left++;
            }
        }
    }
    
    //right
    int xR=76;
    for(int w=0;w<=40;w+=20) {
        for(int h=0;h<=100;h+=20) {
            if(((right+1)==left) && w==40 && h==100) continue;
            int shape=rand() %6;
            if((shape==0 && right<15) || (right==0 && w==40 && h==100)){
                int radius=rand() %7 +3;
                uLCD.filled_circle(xR+w,y+h,radius,color_assign());
                right++;
            }
            else if(shape==1 && right<15) {
                int half_length=rand() %7 +3;
                int x1=(xR+w)-half_length;
                int x2=(xR+w)+half_length;
                int y1=(y+h)-half_length;
                int y2=(y+h)+half_length;
                uLCD.filled_rectangle(x1,y1,x2,y2,color_assign());
                right++;
            }
            else if(shape==2 && right<15) {
                int half_length=rand() %7 +3;
                int x1=(xR+w);
                int y1=(y+h)-half_length;
                int x2=(xR+w)-half_length;
                int y2=(y+h)+half_length;
                int x3=(xR+w)+half_length;
                int y3=(y+h)+half_length;
                uLCD.triangle(x1,y1,x2,y2,x3,y3,color_assign());
                right++;
            }
        }
    }
}

int main() {
    pbLeft.mode(PullUp);
    pbRight.mode(PullUp);
    pbExit.mode(PullUp);
    wait(0.1);
    
    pbExit.attach_deasserted(&hit_callback);
    pbExit.setSampleFrequency();
    
    welcome_screen();
    
    //instantiate running stats
    int accuracy=0;
    int trial=0;
    
    //iteratively randomly generate boards, increment statistics accordingly
    while(game_state == true) {
        //generate board
        int left=0;
        int right=0;
        uLCD.cls();
        uLCD.rectangle(0,0,61,121,WHITE);
        uLCD.rectangle(66,0,127,121,WHITE);
        randomize_board(left,right);
        
        //begin guessing
        int guess=999;
        Timer t; t.start();
        while(pbRight && pbLeft) { 
            wait(.1);
            if(!pbLeft) guess=0;
            if(!pbRight) guess=1;
        }
        t.stop();
        uLCD.cls(); 
        
        //display data, left=0, right=1
        trial++;
        int correct;
        if(left<right) correct=0;
        else correct=1;
        
        if(guess==correct) {
            accuracy++;
            uLCD.printf("correct :)\n\n");
        }
        else uLCD.printf("incorrect :(\n\n");
        float ratio=(float)accuracy/trial;
        uLCD.printf("left: %i \nright: %i \ntrial: %i \naccuracy: %.2f \ntime: %i ms",left,right,trial,ratio,time);
        wait(3);
        uLCD.cls();
    }
}