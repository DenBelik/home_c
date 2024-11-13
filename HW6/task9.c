#include <stdio.h>
#include <inttypes.h>

uint64_t fact(int n) {
    uint64_t res = 1;
    for (int i = n; i > 1; i--) {
        res *= i;
    }
    return res;
}

int main(void) {   
    int num;
    scanf("%d", &num);
    printf("%llu", fact(num));
}