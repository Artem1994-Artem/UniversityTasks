
#include <iostream>
#include <stdio.h>
#define PR(x) printf ("x=%u, *x=%d, &x=%u\n", x, *x, &x)
using namespace std;
void m1() {
    int mass[] = { 100, 200, 300 };
    int* ptr1, * ptr2;
    ptr1 = mass;
    ptr2 = &mass[2];
    PR(ptr1);
    ptr1++;
    PR(ptr1);
    PR(ptr2);
    ++ptr2;
    printf("ptr2-ptr1=%u\n", ptr2 - ptr1);
}
void m2() {
    char mass[] = { 'a', 'b', 'c' };
    char* ptr1, * ptr2;
    ptr1 = mass;
    ptr2 = &mass[2];
    PR(ptr1);
    ptr1++;
    PR(ptr1);
    PR(ptr2);
    ++ptr2;
    printf("ptr2-ptr1=%u\n", ptr2 - ptr1);
}
void m3() {
    double mass[] = { 2.0, 1.5, 3.1};
    double* ptr1, * ptr2;
    ptr1 = mass;
    ptr2 = &mass[2];
    PR(ptr1);
    ptr1++;
    PR(ptr1);
    PR(ptr2);
    ++ptr2;
    printf("ptr2-ptr1=%u\n", ptr2 - ptr1);
}
int main()
{
    m1();
    m2();
    m3();
}
