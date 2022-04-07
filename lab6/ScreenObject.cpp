#include "ScreenObject.h"

ScreenObject :: ScreenObject(int new_x, int new_y) : x(new_x), y(new_y), visible(true) {}

void ScreenObject :: setX(int new_x) { x = new_x; }

int ScreenObject :: getX() { return x; }

void ScreenObject :: setY(int new_y) { y = new_y; }

int ScreenObject :: getY() { return y; }

void ScreenObject :: setVisibility(bool status) { visible = status; }

bool ScreenObject :: getVisibility() { return visible; }