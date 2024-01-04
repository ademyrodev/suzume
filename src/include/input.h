#ifndef suzume_input_h
#define suzume_input_h

#include <stdbool.h>

#include "algebra.h"
#include "win.h"

void initInput(SuWin *win);

bool keyDown(int key);
bool keyUp(int key);

bool leftClick();
bool rightClick();

Vec3 mousePos();

#endif
