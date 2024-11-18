#include <stdio.h>

int find_max(int max) {
    int temp;
    scanf("%d", &temp);
    if (temp == 0) return max;
    else {
        if (temp > max) max = temp;
    }
    find_max(max);
}

int main(void) {
    int num;
    scanf("%d", &num);
    printf("%d", find_max(num));
    return 0; 
}