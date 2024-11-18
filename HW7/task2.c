#include <stdio.h>

int find_sum(int n) {
    if (n == 1) return 1;
    return n + find_sum(n - 1);
}

int main(void) {
    int x;
    scanf("%d", &x);
    printf("%d", find_sum(x));
    return 0;
}