#include <stdio.h>

int func(int x) {
    if (x >= -2 && x < 2) {
        return x*x;
    } else if (x >= 2) {
        return x*x + 4*x +5;
    } else {
        return 4;
    }
}

int main(void) {
    int a;
    int max = 0;
    scanf("%d", &a);
    while(a) {
        if (func(a) > max) max = func(a);
        scanf("%d", &a);
    }
    printf("%d", max);
    return 0;
}