#include <stdio.h>
#include <limits.h>

int lost_number() {
    int a = 1;
    int min = INT_MAX;
    int max = INT_MIN;
    int sum = 0;
    int sum_min_max = 0;

    while (a != 0) {
        scanf("%d", &a);
        sum += a;

        if (a < min && a != 0) min = a;
        if (a > max) max = a;
    }

    for (int i = min; i <= max; ++i) {
        sum_min_max += i;
    }

    return (sum_min_max - sum);
}

int main() {
    printf("%d", lost_number());
    return 0;
}