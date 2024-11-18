#include <stdio.h>

void convert_bin(int num) {
    if (num == 0) return;
    convert_bin(num / 2);
    printf("%d", num % 2);
}

int main(void) {
    int x;
    scanf("%d", &x);
    if (x == 0) printf("%d", x);
     else convert_bin(x);
    return 0;
}