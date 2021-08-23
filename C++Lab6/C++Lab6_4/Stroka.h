#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class Stroka {
    char *str;
public:
    Stroka(const char* s, int);
    Stroka(const char* s);
    Stroka() {}
    ~Stroka() { }
    Stroka(const Stroka&);
    Stroka& operator= (const Stroka&);
    Stroka& operator+ (const Stroka&);
    int operator== (const Stroka&);
    int dlina();
    void vvod();
    void vyvod();
};

