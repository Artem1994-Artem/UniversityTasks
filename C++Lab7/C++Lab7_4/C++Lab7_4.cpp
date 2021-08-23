#include <iostream>
using namespace std;

class FirstClass    // базовый класс
{
protected:          // спецификатор доступа к элементу value
    int value;
public:
    FirstClass()
    {
        value = 0;
    }

    FirstClass(int input)
    {
        value = input;
    }

    virtual void show_value() final
    {
        cout << value << endl;
    }
};

class SecondClass : public FirstClass   // производный класс
{
public:
    SecondClass() : FirstClass()   // конструктор класса SecondClass вызывает конструктор класса FirstClass
    {}

    SecondClass(int inputS) : FirstClass(inputS)   // inputS передается в конструктор с параметром класса FirstClass
    {}

    void show_value() override {

    }
    void ValueSqr() // возводит value в квадрат. 
    {
        value *= value;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");

    FirstClass F_object(3);     // объект базового класса
    cout << "value F_object = ";
    F_object.show_value();

    SecondClass S_object(4);    // объект производного класса
    cout << "value S_object = ";
    S_object.show_value();  // вызов метода базового класса

    S_object.ValueSqr();        // возводим value в квадрат
    cout << "квадрат value S_object = ";
    S_object.show_value();

    //F_object.ValueSqr();      // базовый класс не имеет доступа к методам производного класса
    cout << endl;
}