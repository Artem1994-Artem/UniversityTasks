#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

void found(char* arr, char* name) {
    fpos_t position;
    char ch1;
    char* arr2 = (char*)malloc(strlen(arr));
    FILE* in2;
    FILE* in1;
    in1 = fopen(name, "r");
    in2 = fopen("Res", "w");
    while (!feof(in1)) {
        ch1 = getc(in1);
        putchar(ch1);
        if (arr[0] == ch1) {
            for (int i = 0; i < strlen(arr); i++) {
                arr2[i] = ch1;
                ch1 = getc(in1);
                putchar(ch1);
                if (i == strlen(arr) - 1){ arr2[i + 1] = '\0';
                if (strcmp(arr, arr2) == 0) {
                    for (int j = 0; j < strlen(arr); j++) fputc(arr2[j], in2);
                }
                }
            }
        } 

    }
    fclose(in1);
    fclose(in2);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    char ch, name[50], z[50];
    FILE* in;
    printf("Введите имя файла для просмотра: ");
    scanf("%s", name);
    if ((in = fopen(name, "r")) == NULL)
        printf("Файл %s не открыт", name);
    else {
        while (!feof(in)) {
            ch = getc(in);
            putchar(ch);
        }
        fclose(in);
        printf("\nВведите подстроку для поиска: ");
        scanf("%s", z);
        found(z, name);
    }
}

