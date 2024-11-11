#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d", &a);
    while(a) {
        b = a % 10;
        a /= 10;
        if (b == (a % 10)) {
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}