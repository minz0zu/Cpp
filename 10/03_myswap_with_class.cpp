#include <iostream>
using namespace std;

/*
    템플릿은 사용자 정의 타입(클래스)에도 적용 가능

*/


class Circle {
    int radius;
public:
    Circle(int radius = 1) : radius(radius) {}
    int getRadius() const {return radius;}
};


template <class T>
void myswap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}


int main() {
    Circle donut(5);
    Circle pizza(20);

    myswap(donut, pizza);

    cout <<donut.getRadius() << " " << pizza.getRadius()<< "\n";
    return 0;

}



