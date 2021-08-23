
#include <iostream>
using namespace std;
template <typename T>
class List {
    struct Node {
        T d;
        Node* next;
    };

public:
    Node* pbeg;
    Node* pend;
    List(T d) {
       pbeg = first(d);
       pend = pbeg;
    }

    Node* first(T d) {
        Node* pv = new Node;
        pv->d = d;
        pv->next = 0;
        return pv;
    }
    void add( T d) {
        Node* pv = new Node;
        pv->d = d;
        pv->next = 0;
        pend->next = pv;
        pend = pv;
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
    Node* insert(T key, T d) {
        if (Node* pkey = find(key)) {
            Node* pv = new Node;
            pv->d = d;
            pv->next = pkey->next;
            pkey->next = pv;
            return pv;
        }
        return 0;
    }
    void show() {
        Node* pv = pbeg;
        while (pv) { 					// вывод списка на экран
            cout << pv->d << ' ';
            pv = pv->next;
        }
    }

};

int main()
{
    List <int> L (1); 	// Формирование первого элемента списка 
    for (int i = 2; i < 6; i++) L.add(i);
    L.insert(2, 200);
    if (!L.remove(5)) cout << "не найден";
    L.show();
}
;
