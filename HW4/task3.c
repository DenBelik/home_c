#include <stdio.h>

int main(void) {
    int a, max;
    scanf("%d", &a);
    while (a) {
        max = (max > a%10) ? max : a%10;
        a /= 10;
    }
    printf("%d", max);
    return 0;
}