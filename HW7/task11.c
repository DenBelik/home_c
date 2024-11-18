#include <stdio.h>

int col_bin(int num) {
    if (num == 0) return 0;
    return (num % 2) + col_bin(num / 2);
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d", col_bin(n));
}