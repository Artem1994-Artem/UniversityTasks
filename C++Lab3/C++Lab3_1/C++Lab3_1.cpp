

#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	int imax = 0, imin = 0;
	int i, n=0;
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	cout << "Введите размер массива: ";
	cout << endl;
	cin >> n;
	int* mas = new int [n];
	for (int i = 0; i < n; i++) mas[i] = rand() / 500;
	

	cout << "Массив до сортировки: ";
	cout << endl;
	for (int i = 0; i < n; i++) 
		cout << mas[i] << ' ';
		cout << endl;

		for (int i = 0; i < n - 1; i++) {
			imin = i;
			for (int j = i + 1; j < n; j++) if (mas[j] < mas[imin]) imin = j;
			int t = mas[i];
			mas[i] = mas[imin];
			mas[imin] = t;
	}
		cout << "Массив после сортировки: ";
		cout << endl;
		for (i = 0; i < n; i++)
			cout << mas[i] << ' ';
			cout << endl;
}


