#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int i = 0;
    char key[] = "qwert";
    char ch, c, name[50];
    char fname[15];
    cout << "Введите имя входного файла\n";
    cin >> fname;;
    ifstream ifs(fname);
    if (!ifs) {
        cout << "Не открывается входной файл " << fname << "\n";
    }
    cout << "Введите имя выходного файла\n";
    cin >> fname;
    ofstream ofs(fname);
    if (!ofs) {
        cout << "Не открывается выходной файл\n";
    }

    while (ifs && ofs)
    {
        ifs.get(c);
        c = c ^ key[i];
        i++;
        if (i == 5) i = 0;
        ofs.put(c);
    }

}

