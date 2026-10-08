#include <iostream>
using namespace std;
/* 함수 재정의 (redefine)
- Derived가 Base와 같은 이름 f()를 만들면 "재정의"
- 하지만 Base 포인터로 호출하면 정적 바인딩(static binding)
-> 컴파일 타임에 "포인터 타입"으로 어떤 함수를 부를 지 결정
- 즉 Base*로 부르면 Base::f()가 실행

다형성(polymorphism)은 같은 부모 타입으로 여러 다른 자식 객체를 다루되,
 시제 객체에 맞는 동작이 실행되는 성질

 -"이름이 같다"와 "다형성이 된다"는 다른 이야기
 - 다형성을 만들려면 부모 쪽 선언이 virtual 키워드를 붙여 가상 함수를 만들어야한다.
*/
class Base {
public:
    virtual void f() {cout << "Base::f() called\n"; }
};
class Derived : public Base {
public:
    void f() { cout << "Derived::f() called\n"; }
};

int main(){
    Derived d;
    Derived* pDer = &d;
    pDer->f(); // Derived

    Base* pBase = pDer; // 업캐스팅
    pBase->f(); // Base

    return 0;
}