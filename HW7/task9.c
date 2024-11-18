#include <stdio.h>

int sum_digits(int n) {
    int sum = 0;
    if (n) sum += n % 10 + sum_digits(n / 10);
    return sum;
}

int main(void) {
    int x;
    scanf("%d", &x);
    printf("%d", sum_digits(x));
    return 0;
}