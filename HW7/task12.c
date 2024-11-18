#include <stdio.h>

void foo(int num, int temp) {
    for (int i = 0; i < temp && num > 0; ++i) {
        printf("%d ", temp);
        --num;
    }
    if (num > 0) foo(num, temp + 1);
}

int main(void) {
    int n;
    scanf("%d", &n);
    foo(n, 1);
}