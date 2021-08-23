
#include <iostream>
using namespace std;
template <typename T, class F>
class List {
    struct Node {
        T d;
        int no;
        string fa;
        Node* next;
    };

public:
    Node* pbeg;
    Node* pend;
    List() {

    }

    Node* first(T d, int no, string fa) {
        Node* pv = new Node;
        pv->d = d;
        pv->no = no;
        pv->fa = fa;
        pv->next = 0;
        return pv;
    }
    void add(T d, int no, string fa) {
        if (pbeg != NULL) {
            Node* pv = new Node;
            pv->d = d;
            pv->no = no;
            pv->fa = fa;
            pv->next = 0;
            pend->next = pv;
            pend = pv;
        }
        else {
            pbeg = first(d, no, fa);
            pend = pbeg;
        }
    }
    Node* find(T d) {
        Node* pv = pbeg;
        while (pv) {
            if (pv->d == d) break;
            pv = pv->next;
        }
        return pv;
    }
    bool remove(T key) {
        if (Node* pkey = find(key)) {
            if (pkey == pbeg) {
                pbeg = (pbeg)->next;
            }
            else
                if (pkey == pend) {
                    Node* current = pbeg;
                    while (current->next != pkey) current = current->next;
                    current->next = 0;
                    pend = current;
                }
                else {
                    Node* current = pbeg;
                    while (current->next != pkey) current = current->next;
                    current->next = pkey->next;
                }
            delete pkey;
            return true;
        }
        return false;
    }
    Node* insert(T key, T d, int no, string fa) {
        if (Node* pkey = find(key)) {
            Node* pv = new Node;
            pv->d = d;
            pv->no = no;
            pv->fa = fa;
            pv->next = pkey->next;
            pkey->next = pv;
            return pv;
        }
        return 0;
    }
    void show() {
        Node* pv = pbeg;
        while (pv) { 					// вывод списка на экран
            cout << "Номер автобуса: "<< pv->d << " Номер маршрута: " << pv->no << " Фамилия водителя: " << pv->fa <<endl;
            pv = pv->next;
        }
    }
    int getno(T key) {
            Node* pv = pbeg;
            while (pv) {
                if (pv->d == key) break;
                pv = pv->next;
            }
            return pv->no;

    }
   string getfa(T key) {
            Node* pv = pbeg;
            while (pv) {
                if (pv->d == key) break;
                pv = pv->next;
            }
            return pv->fa;
    }
};




int main()
{
    int x=0;
    setlocale(LC_ALL, "Rus");
    List <int, string> Park; 	
    List <int, string> Path;
    Park.add(999, 17, "Иванов И.И.");
    Park.add(111, 53, "Петров П.П");
    Park.add(777, 64, "Сидоров С.С");
    Park.add(123, 53, "Кафка Ф.");
    Park.add(222, 13, "Лавкрафт Г.Ф.");
    cout << "Выберите действие:" << endl;
    cout << "1 - показать автобусы в парке" << endl;
    cout << "2 - показать автобусы в пути" << endl;
    cout << "3 - добавить новый автобус" << endl;
    cout << "4 - Выезд автобуса" << endl;
    cout << "5 - Прибытие автобуса" << endl;
    cout << "6 - Закончить" << endl;
    while (x != 6) {
        cin >> x;
        switch (x)
        {
        case 1: 
        {
            cout << "Автобусы в парке: " << endl;
            Park.show();
            break;
        }
        case 2: 
        {
            cout << "Автобусы в пути: " << endl;
            Path.show();
            break;
        }
        case 3: 
        {int z, c;
        string f;
            cout << "Введите номер нового автобуса: " << endl;
            cin >> z;
            cout << "Введите маршрут нового автобуса: " << endl;
            cin >> c;
            cout << "Введите фамилию водителя: " << endl;
            cin >> f;
            Park.add(z, c, f);
            break;
        }
        case 4: 
        {   int z;
            cout << "Введите номер выезжающего автобуса: " << endl;
            cin >> z;
            Path.add(z, Park.getno(z), Park.getfa(z));
            Park.remove(z);
            break;
        }
        case 5:
        {   int z;
        cout << "Введите номер прибывающего автобуса: " << endl;
        cin >> z;
        Park.add(z, Path.getno(z), Path.getfa(z));
        Path.remove(z);
        break;
        }
        default:
            break;
        }
    }
};
