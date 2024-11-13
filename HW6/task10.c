#include <stdio.h>
#include <inttypes.h>

void print_simple(int n) {
    while(n % 2 == 0) {
        printf("%d ", 2);
        n /= 2;
    }

    for (int i = 3; i <= n / i; ++i) {
        while(n % i == 0) {
            printf("%d ", i);
            n /= i;
        }
    }

    if (n > 2) printf("%d", n);
}

int main(void) {   
    int num;
    scanf("%d", &num);
    print_simple(num);
}