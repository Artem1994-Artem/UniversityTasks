

#include <iostream>
#include <string.h>

using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    char str1[] = "qwerty";
    char str2[100];
    strcpy(str2, "1234567890");
    cout << "Пример strlen(): " << strlen(str1) << endl;
    cout << "Пример strcpy(): " << str2 << endl;
    strcat(str2, str1);
    cout << "Пример strcat(): " << str2 << endl;

    cout << "Пример strcmp() если строки не равны: " << strcmp(str2, str1) << endl;
    cout << "Пример strcmp() если строки равны: " << strcmp(str1, str1) << endl;
   
}
