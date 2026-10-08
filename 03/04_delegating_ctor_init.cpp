#include <iostream>
using namespace std;
/*
1) 멤버 초기화 리스트: 생성자 본문 전에 멤버를 초기화 (문법: x(a), y(b))
2) 위임 생성자: 한 생성자가 다른 생성자를 호출하여 초기화 (문법: Circle() : Circle(1) {})
*/

class Circle {
private:
    int radius; //보호할 상태 (외부 직접 접근 불가)
public:
    ////////////////////////////////////////////
    Circle() : Circle(1) {} // 기본 생성자: 반지름 1로 초기화
    Circle(int r) : radius(r) {} // 매개변수가 있는 생성자
    ////////////////////////////////////////////
    double getArea();
};
/*
    /////////////////////////////////////////////
    Circle::Circle() : Circle(1) {} // 기본 생성자: 반지름 1로 초기화
    Circle::Circle(int r) : radius(r) {} // 매개변수가 있는 생성자
    ////////////////////////////////////////////
*/
double Circle::getArea() {
    return 3.14159 * radius * radius;
};

int main(){
    Circle donut(1); // 객체 생성:Circle 타입의 인스턴스 donut 생성
    cout << "Donut area: " << donut.getArea() << "\n";
    
    Circle pizza(10);
    cout << "Pizza area: " << pizza.getArea() << "\n";
    return 0;
}