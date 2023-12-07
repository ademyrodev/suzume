#include "input/input.h"
#include <stdio.h>

void temporaryKbdCallback(unsigned char key, int x, int y) {
    printf("%c was pressed\n", key);
    printf("%d %d\n", x, y);
}
