#include <stdio.h>
#include <stdlib.h>

int is_digit(char c) {
    return ((c >= '0') && (c <= '9'));
  }

int main(void) {
    char c;
    int hor;
    int vert;
    while ((c = getchar()) != '\n') {
        if (is_digit(c)) vert = c - '0';
        else hor = c - 64;
    }

    (hor % 2 == 0 && vert % 2 == 1) || (vert % 2 == 0 && hor % 2 == 1) ? printf("WHITE") : printf("BLACK");

    return 0;
}
