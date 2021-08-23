#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int i;
    cout << "Введите число\n";
    cin >> i;
    cin.clear();
    if (cin.fail()) {
        cout << "Некоректный тип данных\n";
    }
    if (cin.good()) {
        cout << "Корректный тип данных\n";
    }
    fstream ifs("File");
    cout << ifs.good() << endl; // возвращает true, если установлен goodbit (значит, что с потоком всё ок);
    cout << ifs.fail() << endl; // возвращает true, если установлен failbit (значит, что произошла какая-то НЕ фатальная ошибка);
    cout << ifs.bad()  << endl; // возвращает true, если установлен badbit (значит, что произошла какая-то фатальная ошибка);
    cout << ifs.eof() << endl;  // возвращает true, если установлен eofbit (значит, что поток находится в конце файла);
    cout << "///\n";
    ifs.setstate(ios_base::failbit | ios_base::badbit | ios_base::eofbit);
    cout << ifs.good() << endl; 
    cout << ifs.fail() << endl;
    cout << ifs.bad() << endl;
    cout << ifs.eof() << endl;
}


