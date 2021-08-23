#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>

int main()
{
    setlocale(LC_ALL, "Russian");
    int x = 0, y = 0;
    int ind = 0;
    char ch, name[50];
    FILE* in;
    printf("Введите имя файла для просмотра: ");
    scanf("%s", name);
    if ((in = fopen(name, "r")) == NULL)
        printf("Файл %s не открыт", name);
    else while (!feof(in)) {
        ch = getc(in);
        ind = int(ch);
        if (ind > 32 && ind < 1104) x++;
        y++;
        putchar(ch);
    }

    printf("\n Число \"Пустых\" символов: %d", y-x);
}

