#include <iostream>
#include <fstream>
#include<stdlib.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    char name[12];
    fstream fin;
    cout << "Введите имя файла";
    cin >> name;

    fin.open(name, ios::in);
    if (fin) {
        cout << "Файл открыт " << name << endl;
        fin.close();
    }
    else {
        cout << "Не открыт входной файл" << name << endl;
    }
}

