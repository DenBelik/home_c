// Изменить расширение
// В файле .txt записан полный адрес файла (возможно, без расширения). Необходимо изменить его расширение на ".html" и записать результат в файл .txt. 

#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fin, *fout;
    char filename[1000];

    fin = fopen("input.txt", "r");
    fgets(filename, sizeof(filename), fin);

    fclose(fin);
    
    filename[strcspn(filename, "\n")] = 0;

    char *slash = strrchr(filename, '/');
    char *dot = strrchr(slash, '.');
    
    if (dot != NULL) {
        strcpy(dot, ".html");
    } else {
        strcat(filename, ".html");
    }
    
    printf("%s", filename);

    fout = fopen("output.txt", "w");

    fprintf(fout, "%s", filename);
    
    fclose(fout);

    return 0;
}
