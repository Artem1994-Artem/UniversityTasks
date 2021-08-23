

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
	int i, N1, N2;



	for (int i = 0; i < n; i++)
		cout << mas[i] << ' ';
	cout << endl;

	cout << "Введите N1: ";
	cin >> N1;
	cout << "Введите N2: ";
	cin >> N2;
	if (N1<0 || N1 > N2 || N2 >= n) {
		cout << "Некорректные индексы";
	} else {
		for (int i = N1; i < N2; i++) {
			imin = i;
			for (int j = i + 1; j < N2 + 1; j++) if (mas[j] < mas[imin]) imin = j;
			int t = mas[i];
			mas[i] = mas[imin];
			mas[imin] = t;
		}
		for (i = 0; i < n; i++)
			cout << mas[i] << ' ';
		cout << endl;
	}


}

