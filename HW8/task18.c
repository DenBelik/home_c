#include <stdio.h>

void print_multiple(int num) {
    for (int i = 2; i < 10; ++i) {
        printf("%d %d\n", i, num / i);
    }
}

int main(void) {
    int num;
    scanf("%d", &num);
    print_multiple(num);
    return 0;
}