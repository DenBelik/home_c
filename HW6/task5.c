#include <stdio.h>

int Sum(int x) {
    int sum = 0;
    for (int i = 0; i <= x; ++i) {
        sum += i;
    }
    return sum;
}

int main(void) {
    int a;
    scanf("%d", &a);
    printf("%d", Sum(a));
    return 0;
}