// Удалить пробелы из текста
// В файле .txt необходимо удалить все лишние пробелы (в начале предложения и сдвоенные пробелы). 
// Для решения задачи разработать функцию. Результат записать в .txt. 

#include <stdio.h>
#include <string.h>

int remove_spaces(char str[], char res[]) {
    int size = 0;
    int counter = 0;
    int spaces_counter = 0;
    while (str[counter] == ' ') counter++;
    while (counter < strlen(str)) {
        if (str[counter] == ' ') spaces_counter++;
        else spaces_counter = 0;
        if (spaces_counter < 2) 
            res[size++] = str[counter];
        counter++;
    }
    
    return size;
}

int main(void) {
    FILE *fin, *fout;
    char str[1000];
    char result[1000];
    int size;

    fin = fopen("input.txt", "r");

    fgets(str, sizeof(str), fin);
    str[strcspn(str, "\n")] = 0;
    
    fclose(fin);

    size = remove_spaces(str, result);

    //printf("%s", result);

    fout = fopen("output.txt", "w");
    
    for (int i = 0; i < size; ++i) {
        putc(result[i], fout);
    }
    
    fclose(fout);
    
    return 0;

}
