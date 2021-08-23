#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Stroka.h"
using namespace std;


int dlina1(char* ch1) {
    int i = 0;
    while (ch1[i] != '\0') {
        i++;
    }
    return i;
}

void kopir(char* ch1, const char* ch2) {
    while (*ch2) *ch1++ = *ch2++;
    *ch1++ = '\0';
}

void konkat(char* ch1, const char* ch2) {
    while (*ch1)  *ch1++;
    while (*ch2) {
        *ch1++ = *ch2++;
    }
    *ch1++ = '\0';
}

int sravn(char* ch1, const char* ch2) {
    int i = 0;
    while (*ch1 != '\0' || *ch2 != '\0' && *ch1 == *ch2) {
        i = (int)*ch1 - (int)*ch2;
        *ch1++;
        *ch2++;
    }
    return i;
}


Stroka::Stroka(const char* string) {
    kopir(str, string);
}
Stroka::Stroka(const Stroka& s) {
    kopir(str, s.str);
}
Stroka& Stroka :: operator= (const Stroka& s) {
    kopir(str, s.str);
    return *this;
}

Stroka& Stroka :: operator+ (const Stroka& s) {
    konkat(str, s.str);
    return *this;
}

int Stroka :: operator== (const Stroka& s) {
    if ((sravn(str, s.str)) == 0)
        return 1;
    else
        return 0;
}

int Stroka::dlina() {
    return dlina1(str);
}
void Stroka::vvod() {
    cout << "¬ведите строку: ";
    cin >> str;
}
void Stroka::vyvod() {
    cout << str << "\n";

}

