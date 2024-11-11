#include <stdio.h>
#include <stdbool.h>

bool isLucky(int num) {
    int sum = 0;
    int comp = 1;
    while (num) {
        sum += num % 10;
        comp *= num % 10;
        num /= 10;
    }

    return((comp == sum) ? true : false);
}

int main(void) {
    int a;
    scanf("%d", &a);
    for (int i = 10; i <= a; ++i) {
        if (isLucky(i)) printf("%d ", i);
    }
    return 0;
}