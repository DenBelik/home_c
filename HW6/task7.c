#include <stdio.h>

int foo(int num, int sys) {
    if (num == 0) return;
    int res = num % sys;
    num /= sys;
    foo(num, sys);
    printf("%d", res);
}

int main(void) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (a == 0) printf("0");
    else foo(a, b);
    return 0;
}