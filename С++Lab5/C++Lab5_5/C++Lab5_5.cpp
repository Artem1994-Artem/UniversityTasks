#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    int i = 0;
    char key[] = "qwert";
    char ch, c, name[50];
    FILE* in;
    FILE* in2;
    in2 = fopen("Res", "w");
    printf("Введите имя файла для просмотра: ");
    scanf("%s", name);
    if ((in = fopen(name, "r")) == NULL)
        printf("Файл %s не открыт", name);
    else while (!feof(in)) {
        ch = getc(in);
        putchar(ch);
        c = ch;
        c = c ^ key[i];
        i++;
        if (i == 5) i = 0;
        fputc(c, in2);
    }

    fclose(in);
    fclose(in2);
}

