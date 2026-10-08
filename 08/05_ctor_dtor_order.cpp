#include <iostream>
using namespace std;
/*  생성자/소멸자 실행순서
1) 생성순서 Base -> Derived (부모 먼저)
2) 소멸순서: Derived -> Base (자식 먼저)
이유: 파생 클래스가 기본 클래스 상태를 기반으로 동작하므로,
기본 클래스 부분이 먼저 준비되어야 함.
*/
class A{
public:
    A() {cout << "Ctor A\n"; }
    ~A() {cout << "Dtor A\n"; }
};

class B : public A{
public: 
    B() {cout << "Ctor B\n"; }
    ~B() {cout << "Dtor B\n"; }
};

class C : public B{
public:
    C() {cout << "Ctor C\n"; }
    ~C() {cout << "Dtor C\n"; }
};
int main(){
    C c;
    return 0;
}