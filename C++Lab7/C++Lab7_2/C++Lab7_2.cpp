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

    void show_value()
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

    virtual void ValueSqr() // возводит value в квадрат. 
    {
        value *= value;
    }
};
class ThirdClass : public SecondClass {
public:
    ThirdClass() : SecondClass() {}
    ThirdClass(int inputS) : SecondClass(inputS) {}
    void ValueSqr() override {
        value = value * value * value;
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

    ThirdClass T_object(2);
    cout << "value T_object = ";
    T_object.show_value();

    T_object.ValueSqr();        // возводим value в куб
    cout << "куб value T_object = ";
    T_object.show_value();
    
    cout << endl;
}