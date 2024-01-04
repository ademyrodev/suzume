#include <stdio.h>

#include "algebra.h"
#include "input.h"
#include "win.h"

int main(void) {
    if (!glfwInit()) {
        return 1;
    }

    SuWin *win = newSuWin(800, 600, "My Window");

    if (!win) {
        glfwTerminate();
        return 1;
    }

    initInput(win);

    while (suWinRunning(win)) {
        glfwPollEvents();

        if (keyDown(GLFW_KEY_ESCAPE)) {
            fprintf(stderr, "Exiting...\n");
            break;
        }

        if (rightClick()) {
            fprintf(stderr, "Clack.\n");
        }

        Vec3 mouse = mousePos();
        fprintf(stderr, "x: %f ; y: %f\n", mouse.x, mouse.y);
    }

    closeSuWin(win);
    glfwTerminate();

    return 0;
}
