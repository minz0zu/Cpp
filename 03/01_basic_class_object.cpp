#include <iostream>
using namespace std;
/****   클래스/객체 기본
1) class = 설계도, object(instance) = class로 생선된 실체
2) 멤버 변수 = 상태(state), 멤버 함수 = 행동(behavior)
3) 클래스 밖에서 멤버 함수를 구현할 때는 ClassName::FunctionName()형태로 구현
4) 객체는 '.' 연산자로 멤버에 접근
5) 객체는 여러개 생성 가능, 객체마다 멤버 변수의 값이 다를 수 있음
*/
class Circle {
public:
    int radius; // 멤버 변수; 원의 반지름
    double getArea(); // 멤버 함수: 원의 면적 계산
};

double Circle::getArea(){
    return 3.14159 * radius * radius; //원의 면적 계산
}

int main(){
    Circle donut; // 객체 생성:Circle 타입의 인스턴스 donut 생성
    donut.radius = 1; // 멤버 변수에 값 할당
    cout << "Donut area: " << donut.getArea() << "\n"; // 멤버 함수 호출하여

    Circle pizza; // 또 다른 객체 생성: Circle 타입의 인스턴스 pizza 생성
    pizza.radius = 10; // 멤버 변수에 값 할당
    cout << "Pizza area: " << pizza.getArea() << "\n"; // 멤버 함수 호출출

    return 0;
}