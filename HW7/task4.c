#include <stdio.h>

void print_num(int num) {
    if (num == 0) return;
    print_num(num / 10);
    printf("%d ", num % 10);
}

int main(void) {
    int x;
    scanf("%d", &x);
    if (x == 0) printf("%d", x);
    else print_num(x);
    return 0;
}