#include <stdio.h>

int main(void) {
    int a = 7, b = 5;
    int *p = &a;
    p = &b;
    *p = 8;
    printf("%d %d \n", a, b);
    return 0;
}
