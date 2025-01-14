// Последний номер символа
// В файле .txt дана строка из 1000 символов. Показать номера символов, совпадающих с последним символом строки. Результат записать в файл .txt 

#include <stdio.h>

int main(void) {
    printf("Hello Prg!\n");
    int count = 0;
    char c;
    char str[1000];
    FILE *f_in, *f_out;
    char name_in[] = "input.txt";
    char name_out[] = "output.txt";
    f_out = fopen(name_out, "w");

    if ((f_in = fopen(name_in, "r")) == NULL) {
        perror("Can't open input file!");
        return 1;
    }

    while (((c = getc(f_in)) != EOF) && (c != '\n')) {
        str[count++] = c;
    }

    fclose(f_in);

    for (int i = 0; i < count-1; ++i) {
        if (str[i] == str[count - 1])
            fprintf(f_out, "%d ", i);
    }

    fclose(f_out);

    return 0;
    
}