#include <stdio.h>

int main(void) {
    int a;
    int result = 0;
    scanf("%d", &a);
    while (a) {
        result = (result * 10) + (a % 10);
        a /= 10;
    }
    printf("%d", result);
    return 0;
}