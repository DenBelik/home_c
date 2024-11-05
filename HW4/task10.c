#include <stdio.h>

int main(void) {
    int month;
    scanf("%d", &month);
    if (month > 2 & month <= 5) printf("spring");
    else if (month > 5 & month <= 8) printf("summer");
    else if (month > 8 & month <= 11) printf("autumn");
    else printf("winter");
    return 0;
}