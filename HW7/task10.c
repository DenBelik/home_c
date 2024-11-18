#include <stdio.h>

int is_prime(int n, int delitel) {
    if (delitel*delitel > n) {
        return 1;
    }
    if (n % delitel == 0) {
        return 0;
    }
    return is_prime(n, delitel + 1);
}

int main(void) {
    int x;
    scanf("%d", &x);
    if (x < 2) printf("NO");
    else {
        if (is_prime(x, 2)) printf("YES");
        else printf("NO");
    }
    return 0;
}