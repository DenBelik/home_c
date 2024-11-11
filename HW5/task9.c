#include <stdio.h>

int main(void) {
    int a;
    scanf("%d", &a);
    while(a) {
        if ((a % 10) % 2 != 0) {
            printf("NO");
            return 0;
        }
        a /= 10;
    }
    printf("YES");
    return 0;
}