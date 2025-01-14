// Числа в массив
// В файле .txt дана строка, не более 1000 символов, содержащая буквы, целые числа и иные символы. 
// Требуется все числа, которые встречаются в строке, поместить в отдельный целочисленный массив. 
// Например, если дана строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0. 
// Вывести массив по возрастанию в файл .txt. 

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool is_digit(char c) {
    return (c >= '0' && c <= '9');
}

void sort_array(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i; j < size; ++j) {
            if (arr[i] > arr[j]) {
                arr[i] ^= arr[j];
                arr[j] ^= arr[i];
                arr[i] ^= arr[j];
            }
        }
    }
}

int main(void) {
    FILE *fin, *fout;
    int *arr;
    int buffer = 10;
    int count = 0;
    char c;

    arr = (int*)malloc(buffer * sizeof(int));

    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");

    while (((c = getc(fin)) != EOF) && (c != '\n')) {
        if (is_digit(c)) {
            int temp = 0;
            if (count == buffer) {
                buffer *= 2;
                arr = (int*)realloc(arr, buffer * sizeof(int));
            }

            while (is_digit(c)) {
                temp = temp * 10 + c - '0';
                c = getc(fin);
                if ((c == EOF) || (c == '\n')) break;
            }
            
            arr[count++] = temp;
        }
    }

    fclose(fin);

    sort_array(arr, count);

    for (int i = 0; i < count; ++i) {
        fprintf(fout, "%d ", arr[i]);
    }
    
    free(arr);

    fclose(fout);

    return 0;
}
