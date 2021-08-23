#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Stroka.h"

using namespace std;



int main()
{
    setlocale(LC_ALL, "Russian");
    Stroka s1("qwert"), s3, s4(s1), s5;
    s3.vvod();
    s3 = "asdfg";
    s3.vyvod();
    s5 = s1 + s3 + s4;
    cout << "Длина s5 = " << s5.dlina() << "\n";
    s5.vyvod();
    if (s1 == s5) {
        cout << "Строки s1 и s5 равны\n";
    }
    else {
        if (s1 == s4) {
            cout << "Строки s1 и s4 равны\n";
        }

    }
}

