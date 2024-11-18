#include <stdio.h>

void reverse_num(int n) {
    if (n == 0) return;
    printf("%d ", n % 10);
    reverse_num(n / 10);
}

int main(void) {
    int x;
    scanf("%d", &x);
    if (x == 0) printf("%d", 0);
    else reverse_num(x);
    return 0;
}