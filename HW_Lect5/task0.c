// Сколько различных трехзначных чисел можно получить из заданного натурального N, вычеркивая цифры из его десятичной записи? 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char number[1000];
    scanf("%s", number);
    int length = strlen(number);
    int result = 0;
    int unique_nums[1000] = {0};

    for (int i = 0; i < length; ++i) {
        for (int j = i + 1; j < length; ++j) {
            for (int k = j + 1; k < length; ++k) {
                int num = (number[i] - '0') * 100 + (number[j] - '0') * 10 + (number[k] - '0');
                if (unique_nums[num] == 0 && num > 99) {
                    unique_nums[num] = 1;
                    result++;
                }
            }
        }
    }
    printf("%d", result);
    return 0;
}