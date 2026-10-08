#include <iostream>
using namespace std;
/****   캡슐화: private 멤버 변수 + public 인터페이스
1) 멤버 변수를 private로 숨기면, 외부에서 마음대로 값을 바꿀 수 없다.
2) 대신 public 함수로만 상태를 다룬다.
*/
class Circle {
private:
    int radius; // 보호할 상태 (외부에서 직접 접근 불가)
public:
    Circle(int r){ radius = r; } // 생성자: 객체 생성시 반지름 초기화
    // Circle(int r) : radius(r){} // 이 버전도 있음.
    int getRadius() { return radius; } // 반지름 반환
    void setRadius(int r){ radius = r; } // 반지름 설정
    double getArea(); // 멤버 함수: 원의 면적 계산
};

double Circle::getArea(){
    return 3.14159 * radius * radius; //원의 면적 계산
}

int main(){
    Circle donut(1); // 객체 생성:Circle 타입의 인스턴스 donut 생성
    cout << "Donut radius: " << donut.getRadius() << "\n";
    cout << "Donut area: " << donut.getArea() << "\n";
    
    Circle pizza(10);
    cout << "Pizza radius: " << pizza.getRadius() << "\n";
    cout << "Pizza area: " << pizza.getArea() << "\n";

    return 0;
}