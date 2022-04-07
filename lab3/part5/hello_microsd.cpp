#include "mbed.h"
#include "SDFileSystem.h"
#include "uLCD_4DGL.h"
SDFileSystem sd(p5, p6, p7, p8, "sd");
uLCD_4DGL uLCD(p9, p10, p11); // serial tx, serial rx, reset pin;
int main() {
 uLCD.printf("Hello Micro SD \nCard!\n");

 mkdir("/sd/mydir", 0777);

 FILE *fp = fopen("/sd/mydir/sdtest.txt", "w");
 if(fp == NULL) {
 uLCD.printf("Error Open \n");
 }
 fprintf(fp, "I love ECE2036");
 fclose(fp);
}