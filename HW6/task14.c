#include <stdio.h>
#include <stdbool.h>

bool SumDigit(int x) {
    int sum = 0;
    while(x) {
        sum += x % 10;
        x /= 10;
    }
    return (sum % 2 == 0);
}

int main(void) {   
    int a;
    scanf("%d", &a);
    printf(SumDigit(a) ? "YES" : "NO");
}