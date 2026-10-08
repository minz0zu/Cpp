#include <iostream>
using namespace std;
/* 템플릿 함수 myswap<T>
- template <class T> : T는 "타입 변수"
- 호출할 때 컴파일러 T가 결정하고, 해당 타입 버전 함수를 만들어준다.
*/
template <class T>
void myswap(T& a, T& b) {
    T temp = a;
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