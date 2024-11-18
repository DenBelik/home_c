#include <stdio.h>

void foo(int num) {
    if (num == 0) return;
    printf("%d ", num);
    foo(num - 1);
}

int main(void) {
    int x;
    scanf("%d", &x);
    if (x == 0) printf("%d", 0);
    else foo(x);
    return 0;
}