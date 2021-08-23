
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	int n = 0;
	cout << "Введите размер массива: ";
	cout << endl;
	cin >> n;
	int* mas = new int[n];
	for (int i = 0; i < n; i++) mas[i] = rand() / 500;
	int imin = 0;
	int t = 0, x = 0;

	cout << "Массив до сортировки: ";
	cout << endl;
	for (int i = 0; i < n; i++) { 
		if (mas[i] % 2 == 0) x++;
		cout << mas[i] << ' ';
		
	}	
	cout << endl;

	for (int i = 0; i < n - 1; i++) {
			imin = i;
			for (int j = i + 1; j < n ; j++) if (mas[j] % 2 == 0) imin = j;;
			t = mas[i];
			mas[i] = mas[imin];
			mas[imin] = t;
		}


	for (int i = 0; i < x - 1; i++) {
		imin = i;
		for (int j = i + 1; j < x ; j++) if (mas[j] < mas[imin]) imin = j;;
		t = mas[i];
		mas[i] = mas[imin];
		mas[imin] = t;
	}

	for (int i = x-1; i < n - 1; i++) {
		imin = i;
		for (int j = i+1; j < n ; j++) if (mas[j] > mas[imin]) imin = j; ;
		t = mas[i];
		mas[i] = mas[imin];
		mas[imin] = t;
	}

	cout << "Массив после сортировки: ";
	cout << endl;
		for (int i = 0; i < n; i++)
			cout << mas[i] << ' ';
		cout << endl;
}
