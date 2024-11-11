#include <stdio.h>

int main(void) {
    int a;
    int counter = 0;
    scanf("%d", &a);
    while(a) {
        if (a % 10 == 9) counter++;
        a /= 10;
    }
    printf((counter == 1) ? "YES" : "NO");
    return 0;
}