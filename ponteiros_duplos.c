#include <stdio.h>

int main (void) {
    int x = 5;
    int *p = &x;
    int **pp = &p;
    **pp += 4;
    printf("%d \n", x);
    return 0;
}
