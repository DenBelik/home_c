#include <stdio.h>

void foo() {
    int num;
    scanf("%d", &num);
    if (num != 0) {
        if (num % 2 == 1 || num % 2 == -1) printf("%d ", num);
    } else return;
    foo();
}

int main(void) {
    foo();
    return 0; 
}