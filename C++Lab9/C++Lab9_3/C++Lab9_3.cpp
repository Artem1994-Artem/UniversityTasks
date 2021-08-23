
#include <iostream>
using namespace std;
template <class T>
class Tstack
{
protected:
	int numItem;
	T* item;
public:
	Tstack(size_t size = 10)
	{
		numItem = 0;
		item = new T[size];
	}
	~Tstack()
	{
		delete[] item;
	}
	void push(T t);
	T pop();
	T len();
};
template <class T>
void Tstack <T>::push(T t)
{
	item[numItem++] = t;
}
template <class T>
T Tstack <T>::pop()
{
	return item[--numItem];
}
template <class T>
T Tstack <T>::len() {
	return numItem;
}

void main() {
	Tstack <int> stIn(10);
	Tstack <int> stOut(10);
	Tstack <int> st(10);
	int min = 9999999999999, num = 0, x;
	stIn.push(1);
	stIn.push(5);
	stIn.push(3);
	stIn.push(9);
	stIn.push(7);
	stIn.push(2);
	while (stIn.len() > 0) {
		while (stIn.len() > 0) {
			x = stIn.pop();
			if (x < min) { min = x;}
			st.push(x);
		}
		while (st.len() > 0) {
			x = st.pop();
			if (x == min) { stOut.push(x); }
			else { stIn.push(x); }
		}
		 min = 9999999999999;
	}
	while (stOut.len() > 0) {
		cout << stOut.pop() << " ";
	}
}
