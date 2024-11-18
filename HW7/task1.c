#include <stdio.h>

void print_num(int i, int n) {
    if (i <= n) {
        printf("%d ", i);
        i++;
        print_num(i, n);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    int i = 1;
    print_num(i, n);
    return 0;
}