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

Stroka::Stroka(const char *string) {
    strcpy(str, string);
}
Stroka::Stroka(const Stroka& s) {
    strcpy(str, s.str);
}
Stroka& Stroka :: operator= (const Stroka& s){
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
    cout << "Введите строку: ";
    cin >> str;
}
void Stroka::vyvod() {
    cout << str<<"\n";

}

int main()
{
    setlocale(LC_ALL, "Russian");
    Stroka s1("qwert"), s3, s4(s1), s5;
    s3.vvod();
    s3 = "asdfg";
    s3.vyvod();
    s5 = s1 + s3 + s4;
    cout << "Длина s5 = " << s5.dlina()<<"\n";
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

