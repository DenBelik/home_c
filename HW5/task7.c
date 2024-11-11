#include <stdio.h>
#include <stdbool.h>

int main(void) {
    int a;
    bool nums[10] = {false};
    scanf("%d", &a);
    while(a) {
        if (nums[a%10] == true) {
            printf("YES");
            return 0;
        } else {
            nums[a%10] = true;
        }
        a /= 10;
    }
    printf("NO");
    return 0;
}