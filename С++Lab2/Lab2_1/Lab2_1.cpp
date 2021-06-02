

#include <iostream>
#include <iomanip>
#define N 5
using namespace std;
void m1(float num[N][N]) {  // Минимум матрицы
    float min = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 0 && j == 0)  min = num[i][j];
            if(min > num[i][j]) min = num[i][j];
        }
    }
    cout << "Минимум матрицы: " << min << endl;
}
void m2(float num[N][N]) {   //Максимум матрицы
    float Max = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == 0 && j == 0)  Max = num[i][j];
            if (Max < num[i][j]) Max = num[i][j];
        }
    }
    cout << "Максимум матрицы: " << Max << endl;
}
void m3(float num[N][N]) { //Максимум нижнетреугольной части
    float Max = 0;
    int x, z = 0;
    float arr[12];
    for ( x = 0; x < 5; x++) arr[x] = num[4][x];
    for (int y = 5; y < 9; y++) { 
        arr[y] = num[z][4];
        z++;
    }
    z = 1, x = 3;
    for (int c = 9; c < 12; c++) {
        arr[c] = num[x][z];
        z++;
        x--;
    }
    for (int i = 0; i < 12; i++) {
        if (i == 0)  Max = arr[i];
        if (Max < arr[i]) Max = arr[i];
   }
    cout << "Максимум нижнетреугольной части: " << Max << endl;
}

void m4(float num[N][N]) { //Максимум верхнетреугольной части
    float Max = 0;
    int x, z = 0;
    float arr[12];
    for (x = 0; x < 5; x++) arr[x] = num[0][x];
    for (int y = 5; y < 9; y++) {
        arr[y] = num[z][0];
        z++;
    }
    z = 1, x = 3;
    for (int c = 9; c < 12; c++) {
        arr[c] = num[x][z];
        z++;
        x--;
    }
    for (int i = 0; i < 12; i++) {
        if (i == 0)  Max = arr[i];
        if (Max < arr[i]) Max = arr[i];
    }
    cout << "Максимум верхнетреугольной части: " << Max << endl;
}
void m5(float num[N][N]) { //Минимум нижнетреугольной части
    float min = 0;
    int x, z = 0;
    float arr[12];
    for (x = 0; x < 5; x++) arr[x] = num[4][x];
    for (int y = 5; y < 9; y++) {
        arr[y] = num[z][4];
        z++;
    }
    z = 1, x = 3;
    for (int c = 9; c < 12; c++) {
        arr[c] = num[x][z];
        z++;
        x--;
    }
    for (int i = 0; i < 12; i++) {
        if (i == 0)  min = arr[i];
        if (min > arr[i]) min = arr[i];
    }
    cout << "Минимум нижнетреугольной части: " << min << endl;
}
void m6(float num[N][N]) { //Минимум верхнетреугольной части
    float min = 0;
    int x, z = 0;
    float arr[12];
    for (x = 0; x < 5; x++) arr[x] = num[0][x];
    for (int y = 5; y < 9; y++) {
        arr[y] = num[z][0];
        z++;
    }
    z = 1, x = 3;
    for (int c = 9; c < 12; c++) {
        arr[c] = num[x][z];
        z++;
        x--;
    }
    for (int i = 0; i < 12; i++) {
        if (i == 0)  min = arr[i];
        if (min > arr[i]) min = arr[i];
    }
    cout << "Минимум верхнетреугольной части: " << min << endl;
}
void m7(float num[N][N]) { //Минимум главной диагонали
    int x = 4; float min;
    for (int i = 0; i < 5; i++) {
        if (i == 0) min = num[i][x];
        if (min > num[x][i]) min = num[x][i];
        x--;
    }
    cout << "Минимум главной диагонали: " << min << endl;
}
void m8(float num[N][N]) { //Максимум главной диагонали
    int x = 4; float max;
    for (int i = 0; i < 5; i++) {
        if (i == 0) max = num[i][x];
        if (max < num[x][i]) max = num[x][i];
        x--;
    }
    cout << "Максимум главной диагонали: " << max << endl;
}
void m9(float num[N][N]) { //Минимум второстепенной диагонали
    float min;
    for (int i = 0; i < 5; i++) {
        if (i == 0) min = num[i][i];
        if (min > num[i][i]) min = num[i][i];
    }
    cout << "Минимум второстепенной диагонали: " << min << endl;
}
void m10(float num[N][N]) { //Максимум второстепенной диагонали
    float max;
    for (int i = 0; i < 5; i++) {
        if (i == 0) max = num[i][i];
        if (max > num[i][i]) max = num[i][i];
    }
    cout << "Максимум второстепенной диагонали: " << max << endl;
}
void m11(float num[N][N]) { //Среднеарифмитическое значение элементов матрицы
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += num[i][j];
        }
    }
    sum = sum / 25;
    cout << "Среднеарифмитическое значение элементов матрицы: " << sum << endl;
}
void m12(float num[N][N]) { //Среднеарифмитическое значение элементов верхнетреугольной части матрицы
    float sum = 0;
    int x, z = 0;
    for (x = 0; x < 5; x++) sum += num[0][x];
    for (int y = 5; y < 9; y++) {
        sum += num[z][0];
        z++;
    }
    z = 1, x = 3;
    for (int c = 9; c < 12; c++) {
        sum += num[x][z];
        z++;
        x--;
    }
    sum = sum / 12;
    cout << "Среднеарифмитическое значение элементов верхнетреугольной части матрицы: " << sum << endl;
}
void m13(float num[N][N]) { //Среднеарифмитическое значение элементов нижнетреугольной части матрицы
    float sum = 0;
    int x, z = 0;
    for (x = 0; x < 5; x++) sum += num[4][x];
    for (int y = 5; y < 9; y++) {
        sum += num[z][4];
        z++;
    }
    z = 1, x = 3;
    for (int c = 9; c < 12; c++) {
        sum += num[x][z];
        z++;
        x--;
    }
    sum = sum / 12;
    cout << "Среднеарифмитическое значение элементов нижнетреугольной части матрицы: " << sum << endl;
}
void m14(float num[N][N]) { // Сумма строк матрицы
    float sum1=0, sum2=0, sum3=0, sum4=0, sum5=0;
    for (int i = 0; i < N; i++) {
            sum1 += num[0][i];
            sum2 += num[1][i];
            sum3 += num[2][i];
            sum4 += num[3][i];
            sum5 += num[4][i];
        }
    cout << "Сумма первой строки:     " << sum1 << endl;
    cout << "Сумма второй строки:     " << sum2 << endl;
    cout << "Сумма третьей строки:    " << sum3 << endl;
    cout << "Сумма четвёротой строки: " << sum4 << endl;
    cout << "Сумма пятой строки:      " << sum5 << endl;
}
void m15(float num[N][N]) { // Сумма столбцов матрицы
    float sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
    for (int i = 0; i < N; i++) {
        sum1 += num[i][0];
        sum2 += num[i][1];
        sum3 += num[i][2];
        sum4 += num[i][3];
        sum5 += num[i][4];
    }
    cout << "Сумма первого столбца:    " << sum1 << endl;
    cout << "Сумма второго столбца:    " << sum2 << endl;
    cout << "Сумма третьего столбца:   " << sum3 << endl;
    cout << "Сумма четвёртого столбца: " << sum4 << endl;
    cout << "Сумма пятого столбца:     " << sum5 << endl;
}
void m16(float num[N][N]) { // Минимальное значеине строк
    float sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
        for (int j = 0; j < N; j++) {
            if (j == 0) sum1 = num[0][j];
            if (sum1 > num[0][j]) sum1 = num[0][j];
        }
        for (int j = 0; j < N; j++) {
            if (j == 0) sum2 = num[1][j];
            if (sum2 > num[1][j]) sum1 = num[1][j];
        }
        for (int j = 0; j < N; j++) {
            if (j == 0) sum3 = num[2][j];
            if (sum1 > num[2][j]) sum1 = num[2][j];
        }
        for (int j = 0; j < N; j++) {
            if (j == 0) sum4 = num[3][j];
            if (sum4 > num[3][j]) sum1 = num[3][j];
        }
        for (int j = 0; j < N; j++) {
            if (j == 0) sum5 = num[4][j];
            if (sum5 > num[4][j]) sum5 = num[4][j];
        }
        cout << "Минимальное значение первой  строки:   " << sum1 << endl;
        cout << "Минимальное значение второй  строки:   " << sum2 << endl;
        cout << "Минимальное значение третьей строки:   " << sum3 << endl;
        cout << "Минимальное значение четвертой строки: " << sum4 << endl;
        cout << "Минимальное значение пятой строки:     " << sum5 << endl;
}
void m17(float num[N][N]) { // Минимальное значеине столбцов
    float sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
    for (int j = 0; j < N; j++) {
        if (j == 0) sum1 = num[j][0];
        if (sum1 > num[j][0]) sum1 = num[j][0];
    }
    for (int j = 0; j < N; j++) {
        if (j == 0) sum2 = num[j][1];
        if (sum2 > num[j][1]) sum1 = num[j][1];
    }
    for (int j = 0; j < N; j++) {
        if (j == 0) sum3 = num[j][2];
        if (sum1 > num[j][2]) sum1 = num[j][2];
    }
    for (int j = 0; j < N; j++) {
        if (j == 0) sum4 = num[j][3];
        if (sum4 > num[j][3]) sum1 = num[j][3];
    }
    for (int j = 0; j < N; j++) {
        if (j == 0) sum5 = num[j][4];
        if (sum5 > num[j][4]) sum5 = num[j][4];
    }
    cout << "Минимальное значеине первого столбца:    " << sum1 << endl;
    cout << "Минимальное значеине второго столбца:    " << sum2 << endl;
    cout << "Минимальное значеине третьего столбца:   " << sum3 << endl;
    cout << "Минимальное значеине четвёртого столбца: " << sum4 << endl;
    cout << "Минимальное значеине пятого столбца:     " << sum5 << endl;
}
void m18(float num[N][N]) { // Максимальное значеине строк
    float sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
    for (int j = 0; j < N; j++) {
        if (j == 0) sum1 = num[0][j];
        if (sum1 < num[0][j]) sum1 = num[0][j];
    }
    for (int j = 0; j < N; j++) {
        if (j == 0) sum2 = num[1][j];
        if (sum2 < num[1][j]) sum1 = num[1][j];
    }
    for (int j = 0; j < N; j++) {
        if (j == 0) sum3 = num[2][j];
        if (sum1 < num[2][j]) sum1 = num[2][j];
    }
    for (int j = 0; j < N; j++) {
        if (j == 0) sum4 = num[3][j];
        if (sum4 < num[3][j]) sum1 = num[3][j];
    }
    for (int j = 0; j < N; j++) {
        if (j == 0) sum5 = num[4][j];
        if (sum5 < num[4][j]) sum5 = num[4][j];
    }
    cout << "Максимальное значение первой  строки:   " << sum1 << endl;
    cout << "Максимальное значение второй  строки:   " << sum2 << endl;
    cout << "Максимальное значение третьей строки:   " << sum3 << endl;
    cout << "Максимальное значение четвертой строки: " << sum4 << endl;
    cout << "Максимальное значение пятой строки:     " << sum5 << endl;
}
void m19(float num[N][N]) { // Максимальное значеине столбцов
    float sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
    for (int j = 0; j < N; j++) {
        if (j == 0) sum1 = num[j][0];
        if (sum1 < num[j][0]) sum1 = num[j][0];
    }
    for (int j = 0; j < N; j++) {
        if (j == 0) sum2 = num[j][1];
        if (sum2 < num[j][1]) sum1 = num[j][1];
    }
    for (int j = 0; j < N; j++) {
        if (j == 0) sum3 = num[j][2];
        if (sum1 < num[j][2]) sum1 = num[j][2];
    }
    for (int j = 0; j < N; j++) {
        if (j == 0) sum4 = num[j][3];
        if (sum4 < num[j][3]) sum1 = num[j][3];
    }
    for (int j = 0; j < N; j++) {
        if (j == 0) sum5 = num[j][4];
        if (sum5 < num[j][4]) sum5 = num[j][4];
    }
    cout << "Максимальное значеине первого столбца:    " << sum1 << endl;
    cout << "Максимальное значеине второго столбца:    " << sum2 << endl;
    cout << "Максимальное значеине третьего столбца:   " << sum3 << endl;
    cout << "Максимальное значеине четвёртого столбца: " << sum4 << endl;
    cout << "Максимальное значеине пятого столбца:     " << sum5 << endl;
}
void m20(float num[N][N]) { // Среднеарифмитическая строк матрицы
    float sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
    for (int i = 0; i < N; i++) {
        sum1 += num[0][i]/N;
        sum2 += num[1][i]/N;
        sum3 += num[2][i]/N;
        sum4 += num[3][i]/N;
        sum5 += num[4][i]/N;
    }
    cout << "Среднеарифмитическая значение первой  строки:   " << sum1 << endl;
    cout << "Среднеарифмитическая значение второй  строки:   " << sum2 << endl;
    cout << "Среднеарифмитическая значение третьей строки:   " << sum3 << endl;
    cout << "Среднеарифмитическая значение четвертой строки: " << sum4 << endl;
    cout << "Среднеарифмитическая значение пятой строки:     " << sum5 << endl;
}
void m21(float num[N][N]) { // Среднеарифмитическая столбцов матрицы
    float sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
    for (int i = 0; i < N; i++) {
        sum1 += num[i][0]/N;
        sum2 += num[i][1]/N;
        sum3 += num[i][2]/N;
        sum4 += num[i][3]/N;
        sum5 += num[i][4]/N;
    }
    cout << "Среднеарифмитическая значеине первого столбца:    " << sum1 << endl;
    cout << "Среднеарифмитическая значеине второго столбца:    " << sum2 << endl;
    cout << "Среднеарифмитическая значеине третьего столбца:   " << sum3 << endl;
    cout << "Среднеарифмитическая значеине четвёртого столбца: " << sum4 << endl;
    cout << "Среднеарифмитическая значеине пятого столбца:     " << sum5 << endl;
}
void m22(float num[N][N]) { // Сумма верхне- и нижнетреугольных элементов матрицы
    float sum1 = 0, sum2 = 0, res=0;
    int x, z = 0;
    for (x = 0; x < 5; x++) sum1 += num[4][x];
    for (int y = 5; y < 9; y++) {
        sum1 += num[z][4];
        z++;
    }
    z = 1, x = 3;
    for (int c = 9; c < 12; c++) {
        sum1 += num[x][z];
        z++;
        x--;
    }
    z = 0;
    for (x = 0; x < 5; x++) sum2 += num[0][x];
    for (int y = 5; y < 9; y++) {
        sum2 += num[z][0];
        z++;
    }
    z = 1, x = 3;
    for (int c = 9; c < 12; c++) {
        sum2 += num[x][z];
        z++;
        x--;
    }
    res = sum1 + sum2;
    cout << "Сумма верхне- и нижнетреугольных элементов матрицы: " << res << endl;
}
void m23(float num[N][N]) { // Наиболее близкое значение к среднеарифмитической матрицы
    float sum = 0, x = 0, y = num[1][1], min = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += num[i][j];
        }
    }
    sum = sum / 25;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            x = abs(num[i][j] - sum);
            if (x < y) {
                min = num[i][j]; 
                y = x;
            }
        }
    }
    cout << "Наиболее близкое значение к среднеарифмитической матрицы: " << min << endl;
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    float m[N][N];
    int i, j;
    for (i = 0; i < N; i++) 
        for (j = 0; j < N; j++) m[i][j] = rand() / 100.;
        for (i=0; i<N; i++)
        {
        for (j = 0; j < N; j++) 
            cout << setw(8) << setprecision(5) << m[i][j];
            cout << endl;
        }

        m1(m);
        m2(m);
        m3(m);
        m4(m);
        m5(m);
        m6(m);
        m7(m);
        m8(m);
        m9(m);
        m11(m);
        m12(m);
        m13(m);
        m14(m);
        m15(m);
        m16(m);
        m17(m);
        m18(m);
        m19(m);
        m20(m);
        m21(m);
        m22(m);
        m23(m);
    }




