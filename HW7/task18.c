#include <stdio.h>

void print_digits(int n) {
    if (n == 0) return;
    print_digits(n / 10);
    printf("%d ", n % 10);
}

int main(void) {
    int n;
    scanf("%d", &n);
    if (n == 0) printf("%d", 0);
    else print_digits(n);
    return 0;
}