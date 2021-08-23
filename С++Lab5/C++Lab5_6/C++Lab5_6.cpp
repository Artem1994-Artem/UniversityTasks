#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    int i = 0;
    char ch, c, key[50], name[50], name2[50];
    FILE* in;
    FILE* in2;
    printf("Введите имя файла для просмотра: ");
    scanf("%s", name);
    printf("Введите имя файла для записи: ");
    scanf("%s", name2);
    printf("Введите ключь: ");
    scanf("%s", key);
    in2 = fopen(name2, "w");
    if ((in = fopen(name, "r")) == NULL)
        printf("Файл %s не открыт", name);
    else while (!feof(in)) {
        ch = getc(in);
        putchar(ch);
        c = ch;
        c = c ^ key[i];
        i++;
        if (i == strlen(key)) i = 0;
        fputc(c, in2);
    }

    fclose(in);
    fclose(in2);
}

