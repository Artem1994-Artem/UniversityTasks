

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



void kopir(char* ch1, char* ch2) {
    while (*ch2) *ch1++ = *ch2++;
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
    int n = 3, m = 3, i, j;
    char** array = new char* [n];

    for (i = 0; i < n; i++)   array[i] = new char[m];
  
    for (i = 0; i < n; i++) { 
        for (j = 0; j < m; j++) {
            array[i][j] = rand() % 26 + 'a';
            cout << array[i][j] << " ";
        }
        array[i][j] = '\0';
        cout << i+1 << " Строка\n" << endl;
    }
    cout << "\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << "\n";
    cout << "Размер строки: " << dlina1(array[0]) << endl;
    cout << "Сравнение строк до копирования: " << sravn(array[0], array[1]) << endl;
    kopir(array[0], array[1]);
    cout << "После Копирования: " << array[0] << endl;
    cout << "Сравнение строк после копирования: " << sravn(array[0], array[1]) << endl;
    konkat(array[0], array[1]);
    cout << "После сцепления: " << array[0] << endl;
    
}

