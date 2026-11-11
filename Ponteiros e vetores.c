#include <stdio.h>

int main(void) {
    int v[3] = {2, 4, 6};
    int *p = v;
    *(p + 1) = *p + v[2];
    printf("%d %d \n", v[1], *(p + 2));
    return 0;
}
