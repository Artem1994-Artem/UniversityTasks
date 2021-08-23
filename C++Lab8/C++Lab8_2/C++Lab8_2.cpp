
#include <iostream>
#include <fstream>
#include<stdlib.h>
#include<ctype.h>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    char fname[15], c;
    cout << "Введите имя входного файла\n";
    cin >> fname;
    ifstream ifs(fname);
    if (!ifs) {
        cout << "Не открывается входной файл " << fname << "\n";
    }
    cout << "Введите имя выходного файла\n";
    cin >> fname;
    ofstream ofs(fname);
    if (!ofs) {
        cout << "Не открывается выходной файл\n" ;
    }

    while  (ifs && ofs)
    {
        ifs.get(c);
        c = toupper(c);
        ofs.put(c);
    }
}
