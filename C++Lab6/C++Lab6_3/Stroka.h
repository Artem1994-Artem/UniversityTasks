#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Stroka {
    char str[80];
public:
    Stroka(const char* s);
    Stroka() {}
    Stroka(const Stroka&);
    Stroka& operator= (const Stroka&);
    Stroka& operator+ (const Stroka&);
    int operator== (const Stroka&);
    int dlina();
    void vvod();
    void vyvod();
};

