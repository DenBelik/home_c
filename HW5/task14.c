#include <stdio.h>

int main(void) {
    int a;
    int counter = 0;
    while (1) {
        scanf("%d", &a);
        if (a == 0) break;
        counter++;
    }
    printf("%d", counter);
    return 0;
}