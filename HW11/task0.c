//На стандартном потоке ввода задаётся натуральное число N (N > 0), после которого следует последовательность из N целых чисел.
//На стандартный поток вывода напечатайте, сколько раз в этой последовательности встречается максимум. Указание: использовать массивы запрещается. 

#include <stdio.h>
#include <limits.h>

int main(void) {
    int count;
    scanf("%d", &count);

    int max = INT_MIN;
    int max_count = 0;

    for (int i = 0; i < count; ++i) {
        int temp;
        scanf("%d", &temp);
        if (temp == max) {
            max_count++;
        } else if (temp > max) {
            max = temp;
            max_count = 1;
        }
    }

    printf("%d", max_count);

    return 0;
    
}