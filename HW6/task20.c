#include <stdio.h>

int main(void) {   
    int sum1 = 0;
    int sum2 = 0;
    char c;
    c = getchar();
    if (c == ')') {
        printf("NO");
        return 0;
    } else {
        sum1++;
    }
    while ((c = getchar()) != '.') {
        if (c == '(') sum1++;
        else sum2++;
    }
    printf((sum1 == sum2) ? "YES" : "NO");
    return 0;
}