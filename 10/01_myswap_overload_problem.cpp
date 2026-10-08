#include <iostream>
using namespace std;

/*
    중복 함수의 문제 : 타입만 다르고 내용은 동일
    myswap(int&, int&)와 myswap(double&, double&)는 내용이 완전히 동일하다.
*/

void myswap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void myswap(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

int main() {
    int a = 1, b=2;
    myswap(a,b);
    cout <<a << " " << b << "\n";

    double c = 0.4, d = 12.6;

    myswap(c, d);
    cout<< c << " " << d << "\n";

    return 0;
}