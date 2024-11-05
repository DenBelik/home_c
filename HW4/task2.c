#include <stdio.h>

int main(void) {
    int a, b, c, max;
    scanf("%d%d%d", &a, &b, &c);
    max = (b > a) ? b : a;
    max = (max > c) ? max : c;
    printf("%d", max);
    return 0;
}