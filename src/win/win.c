#include <stdlib.h>

#include "win.h"

SuWin *newSuWin(int width, int height, const char *name) {
    SuWin *win = malloc(sizeof (*win));

    if (!win) {
        return NULL;
    }

    win->itself = glfwCreateWindow(width, height, name, NULL, 
                                   NULL);

    if (!win->itself) {
        free(win);
        return NULL;
    }

    glfwMakeContextCurrent(win->itself);

    return win;
}

void closeSuWin(SuWin *win) {
    glfwDestroyWindow(win->itself);
    win->itself = NULL;
    free(win);
}

bool suWinRunning(SuWin *win) {
    return !glfwWindowShouldClose(win->itself);
}
