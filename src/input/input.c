#include "core.h"
#include "input.h"

#include <GLFW/glfw3.h>

#ifdef SUZUME_DEBUG
#include <stdio.h>
#endif

static GLFWwindow *window;
static Vec3 staticMousePos = { 0 };

static void mouseCallback(GLFWwindow *window, double x, double y) {
    IGNORE_PARAM(window);

    staticMousePos.x = x;
    staticMousePos.y = y;
}

void initInput(SuWin *win) {
    window = win->itself;
    glfwSetCursorPosCallback(window, mouseCallback);
}

bool keyDown(int key) {
    return glfwGetKey(window, key) == GLFW_PRESS;
}

bool keyUp(int key) {
    return glfwGetKey(window, key) == GLFW_RELEASE;
}

bool leftClick() {
    return glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT) ==
    GLFW_PRESS;
}

bool rightClick() {
    return glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) ==
    GLFW_PRESS;
}

Vec3 mousePos() {
    return staticMousePos;
}
