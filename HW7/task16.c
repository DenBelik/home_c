#include <stdio.h>

int is2pow(int n) {
    if (n == 1) return 1;
    else if (n % 2 != 0 || n == 0) return 0;
    else return is2pow(n / 2);
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf(is2pow(n) ? "YES" : "NO");
}