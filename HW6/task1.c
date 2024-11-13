#include <stdio.h>

int Module(int x) {
    if (x < 0) x = -x;
    return x;
}

int main(void) {
    int a;
    scanf("%d", &a);
    printf("%d", Module(a));
    return 0;
}