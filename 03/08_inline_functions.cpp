#include <iostream>
#include <ostream>
using namespace std;
/*
1) inline은 컴파일러에게 "함수 호출 대신, 직접 코드 삽입을 해도 된다"는 힌트(강제 X)
주로 짧은 함수/성능 최적화 목적
2) 장점: 호출 오버헤드 감소 / 단점: 코드 크기 증가
3) 클래스 내부에서 정의된 멤버 함수는 자동으로 inline이 된다.
*/
inline int odd(int x) {
    return x % 2; // x가 홀수면 1, 짝수면 0 반환
}
class Circle {
private:
    int radius;
public:
    Circle(int r) : radius(r) {}
    // 선언부내부 구현 --> 자동으로 inline
    double getArea() {
        return 3.14159 * radius * radius;
    }
};

int main() {
    cout << odd(5) << endl;
    cout << odd(4) << endl;
    Circle c(10);
    cout << "Cirle area: " << c.getArea() << endl; // 314.159 출력
    return 0;
}