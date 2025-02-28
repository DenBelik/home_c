#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void reverse_string(const char* src, char* dest, int len) {
    for (int i = 0; i < len; ++i) {
        dest[i] = src[len - 1 - i];
    }
    dest[len] = '\0';
}

int find_prefix_suffix(const char* str1, const char* str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int i = 0;
    int j = len2 - 1;
    char temp1[1000] = {};
    char temp2[1000] = {};
    int counter = 0;
    int max_pref_suf = 0;
    while (i <= len1 && j >= 0) {
        temp1[counter] = str1[i];
        temp2[counter] = str2[j];
        counter++;
        i++;
        j--;
        char buf[1000];
        reverse_string(temp2, buf, counter);
        if (strcmp(temp1, buf) == 0) {
            max_pref_suf = counter;
        }
    }
    return max_pref_suf;
}

int main(void) {
    char str1[1000], str2[1000];

    scanf("%s", str1);
    scanf("%s", str2);

    int res1 = find_prefix_suffix(str1, str2);
    int res2 = find_prefix_suffix(str2, str1);

    printf("%d %d\n", res1, res2);

    return 0;
}
