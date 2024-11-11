#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int a;
    int sum = 0;
    scanf("%d", &a);

    while (a) {
        sum += a % 10;
        a /= 10;
    }
    printf((sum == 10) ? "YES" : "NO");
    return 0;
}