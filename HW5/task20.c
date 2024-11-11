#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int a;
    scanf("%d", &a);
    if (a <= 1) {
        printf("NO");
        return 0;
    } else {
        for (int i = 2; i * i <= a; ++i) {
            if (a % i == 0) {
                printf("NO");
                return 0;
            }
        }
        printf("YES");
        return 0;
    }
}