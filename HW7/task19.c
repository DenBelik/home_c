#include <stdio.h>

int acounter(void) {
    char c;
    scanf("%c", &c);
    if (c == '.') return 0;
    if (c == 'a') return acounter() + 1;
    else return acounter();
}

int main (void) {
    printf("%d", acounter());
    return 0;
}