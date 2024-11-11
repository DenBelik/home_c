#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d%d", &a, &b);
    while (b) {
        int buf = b;
        b = a % b;
        a = buf;
    }
    printf("%d", a);
    return 0;
}