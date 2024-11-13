#include <stdio.h>
#include <inttypes.h>

uint64_t pow(int num, int st) {
    uint64_t res = 1;
    if (st == 0) {
        return res;
    }
    for (int i = 1; i <= st; ++i) {
        res *= num;
    }
    return res;
}

uint64_t foo(int n) {
    return pow(2, n-1);

}

int main(void) {
    int a;
    scanf("%d", &a);
    printf("%llu", foo(a));
    return 0;
}