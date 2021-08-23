#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>


int main()
{
	setlocale(LC_ALL, "Russian");
	int i = 0, j = 0;
	char ch, name[50], per = '\0';
	char c = '-';
	FILE* in;
	FILE* in2;
	in2 = fopen("Res", "w");
	if ((in = fopen("test.txt", "r")) == NULL)
		printf("Файл test.txt не открыт");
	else while (!feof(in)) {
		ch = getc(in);
		if (ch == c) ch = getc(in);
		if (ch > 48 && ch < 57) {
			per = ch;
			ch = getc(in);
		}
		if (ch == '\f') {
			fputc(per, in2);
			putchar(per);
		}
		fputc(ch, in2);
		putchar(ch);
	}
	fclose(in);
	fclose(in2);
}

