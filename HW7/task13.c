#include <stdio.h>

void foo(int num, int delitel) {
    if (num % delitel == 0) {
        printf("%d ", delitel);
        num /= delitel;
    } else {
        delitel++;
    }
    if (num > 1) foo(num, delitel);
}

int main(void) {
    int n;
    scanf("%d", &n);
    if (n > 1) foo(n, 2);
    return 0;
}