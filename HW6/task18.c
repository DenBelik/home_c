#include <stdio.h>
#include <stdbool.h>

bool is_digit(char x) {
    if (x >= '0' && x <= '9') return true;
    else return false;
}

int main(void) {   
    char c;
    int sum = 0;
    while ((c = getchar()) != '.') {
        if (is_digit(c)) sum++;
    }
    printf("%d", sum);
    return 0;
}