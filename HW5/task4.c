#include <stdio.h>

int main(void) {
    int a, counter;
    scanf("%d", &a);
    while(a) {
        a /= 10;
        counter++;
    }
    if (counter == 3) printf("YES");
    else printf("NO");
    return 0;
}