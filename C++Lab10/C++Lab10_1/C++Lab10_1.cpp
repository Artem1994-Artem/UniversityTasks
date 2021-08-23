#include <iostream> 
using namespace std;
struct Node {
	int d;
	Node* next;
};

Node* first(int d);
void add(Node** pend, int d);
Node* find(Node* const pbeg, int i);
bool remove(Node** pbeg, Node** pend, int key);
Node* insert(Node* const pbeg, Node** pend, int key, int d);


int main() {
	Node* pbeg = first(1); 	// Формирование первого элемента списка 
	Node* pend = pbeg; 	// Список заканчивается, едва начавшись
	// Добавление в конец списка четырех элементов 2. 3. 4.	и 5:
	for (int i = 2; i < 6; i++) add(&pend, i);
	// Вставка элемента 200 после элемента 2:
	insert(pbeg, &pend, 2, 200);
	// Удаление элемента 5:
	if (!remove(&pbeg, &pend, 5)) cout << "не найден";
	Node* pv = pbeg;
	while (pv) { 					// вывод списка на экран
		cout << pv->d << ' ';
		pv = pv->next;
	}
	return 0;
}

Node* first(int d) {

	Node* pv = new Node;
	pv->d = d;
	pv->next = 0;
	return pv;
}

void add(Node** pend, int d) {
	Node* pv = new Node;
	pv->d = d;
	pv->next = 0;
	(*pend)->next = pv;
	*pend = pv;
}

Node* find(Node* const pbeg, int d) {
	Node* pv = pbeg;
	while (pv) {
		if (pv->d == d) break;
		pv = pv->next;
	}
	return pv;
}

bool remove(Node** pbeg, Node** pend, int key) {
	if (Node* pkey = find(*pbeg, key)) {
		if (pkey == *pbeg) {
			*pbeg = (*pbeg)->next;
		}
		else
			if (pkey == *pend) {
				Node* current = *pbeg;
				while (current->next != pkey) current = current->next;
				current->next = 0;
				*pend = current;
			}
			else {
				Node* current = *pbeg;
				while (current->next != pkey) current = current->next;
				current->next = pkey->next;
			}
		delete pkey;
		return true;
	}
	return false;
}

Node* insert(Node* const pbeg, Node** pend, int key, int d) {
	if (Node* pkey = find(pbeg, key)) {
		Node* pv = new Node;
		pv->d = d;
		pv->next = pkey->next;
		pkey->next = pv;
		return pv;
	}
	return 0;
}