#include <stdio.h>

void ajustar(int *p, int *q) {
    *p += 2;
    *q += *p;
}

int main(void) {
    int x = 3;
    ajustar(&x, &x);
    printf("%d\n", x);
    return 0;
}Ponteiros e funções em C
