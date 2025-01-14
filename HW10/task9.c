// Удалить повторяющиеся символы
// В файле .txt строка из меленьких и больших английских букв, знаков препинания и пробелов. 
// Требуется удалить из нее повторяющиеся символы и все пробелы. Результат записать в файл .txt. 


#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fin, *fout;
    char str[1000];
    char result[1000];
    char c;
    int size = 0;
    int res_size = 0;

    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");

    while (((c = getc(fin)) != EOF) && c != '\n') {
        str[size++] = c;
    }

    fclose(fin);

    result[0] = '\0';

    for (int i = 0; i < size; ++i) {
        if (str[i] != ' ') {
            char *temp = strchr(result, str[i]);
            if (temp != NULL) {
                continue;
            } else {
                result[res_size++] = str[i];
            }
        }
    }

    for (int i = 0; i < res_size; ++i) {
        fprintf(fout, "%c", result[i]);
    }

    fclose(fout);

    return 0;
}