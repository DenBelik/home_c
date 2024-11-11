#include <stdio.h>

int main(void) {
    int a;
    scanf("%d", &a);
    int max = 0;
    int min = a % 10;
    while (a) {
        if ((a % 10) > max) max = a % 10;
        if ((a % 10) < min) min = a % 10;
        a /= 10;
    }
    printf("%d %d", min, max);
    return 0;
}