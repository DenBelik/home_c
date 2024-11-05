#include <stdio.h>

int main(void) {
    int a;
    int res = 1;
    scanf("%d", &a);
    while (a) {
        res *= a % 10;
        a /= 10;
    }
    printf("%d", res);
    return 0;
}
