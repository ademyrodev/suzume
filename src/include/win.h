#ifndef suzume_win_h
#define suzume_win_h

#include <GLFW/glfw3.h>
#include "core.h"

typedef struct {
    GLFWwindow *itself;
} SuWin;

SuWin *newSuWin(int width, int height, const char *name);
void closeSuWin(SuWin *win);
bool suWinRunning(SuWin *win);

#endif
