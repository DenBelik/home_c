#include <stdio.h>
#include <stdbool.h>

bool int_grow_up(int x) {
    int temp = x % 10;
    x /= 10;
    while(x) {
        if (x % 10 >= temp) return false;
        temp = x % 10;
        x /= 10;
    }
    return true;
}

int main(void) {   
    int a;
    scanf("%d", &a);
    printf(int_grow_up(a) ? "YES" : "NO");
}