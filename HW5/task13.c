#include <stdio.h>

int main(void) {
    int a;
    scanf("%d", &a);
    int even = 0;
    int odd = 0;
    while (a) {
        if ((a % 10 % 2) == 1) odd++;
        else even++;
        a /= 10;
    }
    printf("%d %d", even, odd);
    return 0;
}