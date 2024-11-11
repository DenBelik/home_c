#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int a;
    int num1 = 1;
    int num2 = 1;
    scanf("%d", &a);

    for (int i = 1; i <= a; ++i) {
        printf("%d ", num1);
        int b = num1 + num2;
        num1 = num2;
        num2 = b;
    }

    return 0;
}