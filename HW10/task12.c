// Разобрать на слова
// В файле .txt дано предложение требуется разобрать его на отдельные слова. Напечатать каждое слово на отдельной строке в файл .txt. 

#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fin, *fout;
    char str[1000];
    char *token;

    fin = fopen("input.txt", "r");

    fgets(str, sizeof(str), fin);

    fclose(fin);

    fout = fopen("output.txt", "w");

    token = strtok(str, " ");

    while(token != NULL) {
        fprintf(fout, "%s\n", token);
        token = strtok(NULL, " ");
    }

    fclose(fout);

    return 0;
}