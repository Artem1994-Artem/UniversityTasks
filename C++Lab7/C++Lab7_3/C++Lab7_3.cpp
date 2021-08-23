#include <iostream>
using namespace std;

class FirstClass    // базовый класс
{
public:
    virtual void show_value() = 0;
    virtual void ValueSqr() = 0;
};

class SecondClass : public FirstClass   // производный класс
{
protected:          
    int value;
public:
    SecondClass()   // конструктор класса SecondClass вызывает конструктор класса FirstClass
    {
        value = 0;
    }

    SecondClass(int inputS)   // inputS передается в конструктор с параметром класса FirstClass
    {
        value = inputS;
    }
    void show_value() override {
        cout << "value S_object = " << value << endl;
     
    }

     void ValueSqr() override// возводит value в квадрат. 
    {
        value *= value;
    }
};
class ThirdClass : public FirstClass {
protected:          // спецификатор доступа к элементу value
    double value;
public:
    ThirdClass() { value = 0; }
    ThirdClass(double inputS) { value = inputS; }
    void ValueSqr() override {
        value = value * value * value;
    }
    void show_value() override {
        cout << "value T_object = " << value << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "rus");

    SecondClass S_object(4);    // объект производного класса
    S_object.show_value();  // вызов метода базового класса
    S_object.ValueSqr();        // возводим value в квадрат
    cout << "Квадрат ";
    S_object.show_value();

    ThirdClass T_object(2.5);
    T_object.show_value();
    T_object.ValueSqr();        // возводим value в куб
    cout << "Куб ";
    T_object.show_value();

    cout << endl;
}