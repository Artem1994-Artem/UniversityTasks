

#include <iostream>
#include <atlalloc.h>
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
    *ch1++ = '\0';
}

int sravn(char* ch1, char* ch2) {
    int i = 0;
    while (*ch1 != '\0' || *ch2 != '\0' && *ch1 == *ch2) {
        i = (int)*ch1 - (int)*ch2;
        *ch1++;
        *ch2++;
    }
    return i;
}

void konkat(char* ch1, const char* ch2) {
    while (*ch1)  *ch1++;
    while (*ch2) {
        *ch1++ = *ch2++;
    }
    *ch1++ = '\0';
}
int main()
{
    setlocale(LC_ALL, "Russian");
    char* str1, *str2;
    int x;
    cout << "Укажите длину строки в символах для строк:" << endl;
    cin >> x;
    str1 = (char*)malloc(x + 1);
    str2 = (char*)malloc(x + 1);
    for (int i = 0; i < x; i++) str1[i] = rand() % 26 + 'a';
    str1[x] = '\0';

    for (int i = 0; i < x; i++) str2[i] = rand() % 26 + 'a';
    str2[x] = '\0';
    cout << "Первая строка:" << str1 << endl;
    cout << "Вторая строка:" << str2 << endl;

    int dlina1(char*);
    int dlina2(char*);
    int dlina3(char*);
    void kopir(char*, char*);
    int sravn(char*, char*);
    void konkat(char*, const char*);
    cout << "Длина str1= " << dlina1(str1) << ", str2=" << dlina1(str2) << endl;
    cout << "Длина str1= " << dlina2(str1) << ", str2=" << dlina2(str2) << endl;
    cout << "Длина str1= " << dlina3(str1) << ", str2=" << dlina3(str2) << endl;
    kopir(str1, str2);
    cout << "Результат копирования: " << str1 << endl;
    cout << "Результат сравнения:   " << sravn(str1, str2) << endl;
    konkat(str1, str2);
    cout << "Результат сцепления:   " << str1 << endl;

}

