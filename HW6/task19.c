#include <stdio.h>
#include <stdbool.h>

bool is_digit(char x) {
    if (x >= '0' && x <= '9') return true;
    else return false;
}

int digit_to_num(char c) {
    return c - '0';
}

int main(void) {   
    char c;
    int sum = 0;
    while ((c = getchar()) != '.') {
        if (is_digit(c)) sum += digit_to_num(c);
    }
    printf("%d", sum);
    return 0;
}