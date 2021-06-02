

#include <iostream>
#include <stdio.h>
#include <locale.h>
using namespace std;
void obmen1(int a, int b) {
    int z = a;
    a = b;
    b = z;
}
void obmen2(int* a, int* b) {
    int z = *a;
    *a = *b;
    *b = z;
}
void obmen3(int& a, int& b) {
    int z = a;
    a = b;
    b = z;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int a = 2, b = 5, c;
    cout << "До обмена:  a= " << a << " b=" << b << endl;
    obmen1(a, b);
    cout << "После обмена 1:  a= " << a << " b=" << b << endl;
    obmen2(&a, &b);
    cout << "После обмена 2:  a= " << a << " b=" << b << endl;
    obmen3(a, b);
    cout << "После обмена 3:  a= " << a << " b=" << b << endl;
}

