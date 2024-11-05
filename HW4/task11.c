#include <stdio.h>

int main(void) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    printf((a < b + c) & (b < a + c) & (c < a + b) ? "YES" : "NO");
    return 0;
}