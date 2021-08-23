

#include <iostream>
using namespace std;
#define x 10

void bubble(int *mas, int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (mas[j] > mas[j + 1]) {
                // меняем элементы местами
                temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }
}
void fast(int *mas, int n) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = n - 1;
    //Центральный элемент массива
    int mid = mas[n / 2];
    //Делим массив
    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while (mas[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while (mas[j] > mid) {
            j--;
        }
        //Меняем элементы местами
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);

    //Рекурсивные вызовы, если осталось, что сортировать
    if (j > 0) {
        //"Левый кусок"
        fast(mas, j + 1);
    }
    if (i < n) {
        //"Првый кусок"
        fast(&mas[i], n - i);
    }

}

int main()
{
    srand(time(NULL));
    int arr[x];
    for (int i = 0; i < x; i++) arr[i] = rand() / 500;


    setlocale(LC_ALL, "Russian");
    cout << "Пузырьковая сортировка: ";
    cout << endl;

    int mas1[x];
    for (int i = 0; i < x; i++) mas1[i] = arr[i];

	int n = sizeof(mas1) / sizeof(int);
	for (int i = 0; i < n; i++)
		cout << mas1[i] << ' ';
	cout << endl;
   bubble(mas1, n);
   for (int i = 0; i < n; i++)
       cout << mas1[i] << ' ';
   cout << endl;

   cout << "Быстрая сортировка: ";
   cout << endl;
   int mas2[x];
   for (int i = 0; i < x; i++) mas2[i] = arr[i];

   int n2 = sizeof(mas2) / sizeof(int);
   for (int i = 0; i < n; i++)
       cout << mas2[i] << ' ';
   cout << endl;
   fast(mas2, n2);
    for (int i = 0; i < n; i++)
        cout << mas2[i] << ' ';
    cout << endl;
}

