#include <GL/glut.h>
#include "input/input.h"

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutCreateWindow("input handling");

    glutKeyboardFunc(temporaryKbdCallback);
    glutMainLoop();
    return 0;
}
