#include <iostream>
using namespace std;
int dlina1(char* ch1) {
	int i = 0;
	while (ch1[i] != '\0') {
		i++;
	}
	return i;
}

int dlina2(char* ch1) {
	int i = 0, x = 0;
	while (ch1[i] != '\0') {
		x++;
		i++;
	}
	return x;
}

int dlina3(char* ch1) {
	int i = 0, x = 0;
	do {
		if (ch1[i] != '\0') x++;
		i++;
	} while (ch1[i] != '\0');
	return x;
}

void kopir(char* ch1, char* ch2) {
	while (*ch2) *ch1++ = *ch2++;
	* ch1++ = '\0';
}

int sravn(char* ch1, char* ch2) {
	int i = 0;
	while (*ch1 != '\0' || *ch2 != '\0') {
		i = (int)*ch1 - (int)*ch2;
		*ch1++;
		*ch2++;
	}
	return i;
}

char* konkat(char* ch1, const char* ch2) {
	int i = 0;
	while (ch2[i] != '\0') {
		i++;
	}
	char* сh3 = new char[dlina1(ch1) + i + 1];
	for (i = 0; i < dlina1(ch1); i++) сh3[i] = ch1[i];
	сh3[i] = '\0';
	ch1 = сh3;

	while (*ch1 ) *ch1++;
	while (*ch2 ) {
		*ch1++ = *ch2++;
	}
	*ch1 = '\0';
	return сh3;
}  

int main()
{
	setlocale(LC_ALL, "Russian");
	char str1[] = "qwerty";
	char str2[] = "1234567890";
	int dlina1(char*);
	int dlina2(char*);
	int dlina3(char*);
	void kopir(char*, char*);
	int sravn(char*, char*);
	char* konkat(char*, const char*);
	cout << "Длина str1= " << dlina1(str1) << ", str2=" << dlina1(str2) << endl;
	cout << "Длина str1= " << dlina2(str1) << ", str2=" << dlina2(str2) << endl;
	cout << "Длина str1= " << dlina3(str1) << ", str2=" << dlina3(str2) << endl;
	kopir(str2, str1);
	cout << "Результат копирования: " << str2 << endl;
	cout << "Результат сравнения: " << sravn(str1, str2) << endl;
	cout << "Результат сцепления: " << konkat(str1, str2) << endl;

}