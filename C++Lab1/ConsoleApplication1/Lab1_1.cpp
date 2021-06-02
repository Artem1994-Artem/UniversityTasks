

#include <iostream>

using namespace std;
int main()
{
    int i, k, x;
    int power(int, int);
    cout << "x = ";
    cin >> x;
    for (i = 0; i < 10; i++) {
        k = power(x, i);
        cout << "i=" << i << ", k = " << k << endl;
    }
}

int power(int x, int n) {
    int i, p = 1;
    for (i = 1; i < n; i++) p *= x;
    return p;
}