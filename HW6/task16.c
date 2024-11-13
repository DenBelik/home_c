#include <stdio.h>
#include <stdbool.h>

bool is_prime(int x) {
    if (x <= 1) {
        return false;
    } else {
        for (int i = 2; i * i <= x; ++i) {
            if (x % i == 0) {
                return false;
            }
        }
    }
    return true;
}

int main(void) {   
    int a;
    scanf("%d", &a);
    printf(is_prime(a) ? "YES" : "NO");
}
