#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Stroka.h"
using namespace std;

Stroka::Stroka(const char* string) {
    str = new char[80];
    strcpy(str, string);
}
Stroka::Stroka(const char* string, int i) {
     str = new char[i];
    for (int j = 0; j < strlen(string); j++) {
        str[j] = string[j];
        if (j == strlen(string) - 1) str[j] = '\0';
    }
}

Stroka::Stroka(const Stroka& s) {
    str = new char[80];
    strcpy(str, s.str);
}
Stroka& Stroka :: operator= (const Stroka& s) {
    str = new char[80];
    strcpy(str, s.str);
    return *this;
}

Stroka& Stroka :: operator+ (const Stroka& s) {
    strcat(str, s.str);
    return *this;
}

int Stroka :: operator== (const Stroka& s) {
    if ((strcmp(str, s.str)) == 0)
        return 1;
    else
        return 0;
}

int Stroka::dlina() {
    return strlen(str);
}
void Stroka::vvod() {
    str = new char[80];
    cout << "¬ведите строку: ";
    cin >> str;
}
void Stroka::vyvod() {
    cout << str << "\n";
}