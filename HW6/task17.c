#include <stdio.h>
#include <stdbool.h>

bool is_happy_number(int x) {
    int sum = 0;
    int exp = 1;
    while (x) {
        sum += x % 10;
        exp *= x % 10;
        x /= 10;
    }
    return (sum == exp) ? true : false;
}

int main(void) {   
    int a;
    scanf("%d", &a);
    printf(is_happy_number(a) ? "YES" : "NO");
}
