#include <stdio.h>
#include <ctype.h>

char toUpper(char c) {
    return toupper(c);
}

int main(void) {   
    char c;
    while((c = getchar()) != '.') putchar(toUpper(c));
    return 0;
}