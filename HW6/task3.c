#include <stdio.h>

int middle (int x, int y) {
    return((x + y) / 2);
}

int main(void) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d", middle(a, b));
    return 0;
}