#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d%d", &a, &b);
    for (int i = a; i < b; ++i) {
        printf("%d ", i*i);
    }
    printf("%d", b*b);
    return 0;
}