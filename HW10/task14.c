// Hello name
// В файле .txt в одной строке фамилию, имя и отчество. Сформировать файл приветствие .txt, где останутся имя и фамилия 


#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fin, *fout;
    char name[100];
    char last_name[100];
    int size = 0;
    char c;

    fin = fopen("input.txt", "r");

    while ((c = getc(fin)) != ' ' && c != EOF && c != '\n') {
        last_name[size++] = c;
    }
    last_name[size] = '\0';

    size = 0;

    while (((c = getc(fin)) != ' ' && c != EOF && c != '\n')) {
        name[size++] = c;
    }
    name[size] = '\0';

    fclose(fin);

    fout = fopen("output.txt", "w");

    fprintf(fout, "Hello, %s %s!", name, last_name);

    fclose(fout);

    return 0;
}
