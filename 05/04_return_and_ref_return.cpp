#include <iostream>
using namespace std;
/*
1) 객체 리턴과 대입

*/
class Circle {
    int radius;
public:
    Circle() : radius(1) {}
    // 복사생성자
    Circle(int r) : radius(r) {}
    Circle(Circle& c) : radius(c.radius) {}
    ~Circle() {}
    int getRadius() { return radius; }
    void setRadius(int r) { radius = r; }
    double getArea(){ return 3.14 * radius * radius; }
// 참조 반환을 통함 메서드 체이닝
// - 리턴타입이 Circle& (자신의 참조) -> 호출 후 같은 객체조작기능
// - return *this: this 포인터가 가리키는 객체(자신)의 참조 반환
// - 체이닝 원리: a.plus(1).plus(2)
    Circle& plus(int n){
        radius += n;
        return *this;
    }
};
// 반지름 30인 Circle 객체의 복사본을 반환
Circle getCircle(){
    Circle tmp(30);
    return tmp;
}
char g = 'a'; // 전역 변수
// 참조 반환: 전역 변수 g의 공간 자체를 반환 (복사 아님)
char& findGlobal(){
    return g;
}

// 배열 원소에 대한 참조를 반환
 char& findAt(char s[], int index){
    return s[index];
 }

int main(){
    Circle c;
    cout << c.getArea() << "\n";

    // 반환된 객체를 c에 대입
    cout << c.getArea() << "\n";

    // 전역 변수 참조 리턴
    char a = g;
    cout << "a=" << a << "\n";
    findGlobal() = 'b'; // g의 "공간"에 'b'대입
    cout << "g=" << g << "\n";

    char name[] = "Mike";
    cout << name << "\n";
    // 배열의 0번 원소를 직접 수정
    findAt(name, 0) = 'S';
    cout << name << "\n";
    // 참조를 받아 수정하면 같은 원소가 바뀜
    char& ref = findAt(name, 2);
    ref = 't';
    cout << name << "\n";

    // 객체 자신 참조 리턴 (체이닝)
    Circle aCircle(100);
    aCircle.plus(1).plus(2).plus(3);
    cout << aCircle.getRadius() << "\n";
    return 0;
}