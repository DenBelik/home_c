#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d", &a);
    while(a) {
        b = a % 10;
        a /= 10;
        if ((a % 10) >= b) {
            printf("NO");
            return 0;
        }
    }
    printf("YES");
    return 0;
}