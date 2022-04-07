#include "mbed.h"
#include "uLCD_4DGL.h"
uLCD_4DGL uLCD(p9, p10, p11); // create a global lcd object
int main() {
 uLCD.printf("\nWhat’s up mbed!\n");
}