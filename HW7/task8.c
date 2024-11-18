#include <stdio.h>

void foo(int a, int b) {
    printf("%d ", a);
    if (a == b) return;
    (a > b) ? foo(a - 1, b) : foo(a + 1, b);
}

int main(void) {
    int a, b;
    scanf("%d%d", &a, &b);
    foo(a, b);
    return 0;
}