#include <iostream>
using namespace std;
/*
    객체 포인터 + 객체 배열 + 배열 초기화
    1) 객체 포인터: -> 와 (*p).
    2) 객체 배열: 기본 생성자 호출 (Circle())
    3) 배열 초기화: 원소별 생성자 지정정
*/
class Circle{
    int radius;
public:
    Circle() : radius(1) {} // 기본생성자 꼭 추가
    Circle(int r) : radius(r) {}
    void setRadius(int r){  radius = r; }
    double getArea() {return 3.14*radius*radius; }
};

int main(){
    Circle donut;   // Circle()
    Circle pizza(30);   // Circle(int)

    Circle *p = &donut; // p가 donut 주소 저장

    cout << "[obj] donut area = " << donut.getArea() << "\n";
    cout << "[ptr] donut area = " << p->getArea() << "\n";
    cout << "[ptr] donut area = " << (*p).getArea() << "\n";

    p = &pizza; // p가 pizza 주소 저장
    cout << "[ptr] pizza area = " << p->getArea() << "\n";

    cout << "--- Object array\n";
    Circle circleArray[3];  // 기본생성자 Cirlce()호출
    for(int i=0; i<3; i++) // Circle 배열 출력
        cout << "Circle area: " << circleArray[i].getArea() << "\n";
    for(int i=0; i<3; i++) // 배열 업데이트
        circleArray[i].setRadius(10*i);
    for(int i=0; i<3; i++)  // 배열 출력
        cout << "C`ircle area: " << circleArray[i].getArea() << "\n";

    cout << "--- Object array to ptr\n";
    // 배열 이름은 첫 원소의 주소로 변환
    Circle *ap = circleArray;
    for(int i=0; i<3; i++){
        cout << "Circle area: " << ap->getArea() << "\n";
        ap++; // 그 다음 주소를 가지게 됨.
    }

    // 원소별 생성자 직접 지정
    cout << "array initialization\n";
    Circle initArray[3] = {Circle(10), Circle(20), Circle()};
    for(int i=0; i<3; i++)  // 배열 출력
        cout << "Circle area: " << initArray[i].getArea() << "\n";

    // 2차원 배열
    Circle circles[2][3];
    int r = 1;
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++)
        circles[i][j].setRadius(r++);
    }
    for(int i=0; i<2; i++){
        for(int j=0; j<3; j++)
        cout << "Circle[" << i << "," << j << "] area = "
             << circles[i][j].getArea() << "\n";
    }
    return 0;
}